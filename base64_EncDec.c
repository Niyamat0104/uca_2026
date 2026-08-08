#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INVALID 255

static const char base64_table[64] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z',
    '0','1','2','3','4','5','6','7','8','9','+','/'
};

static unsigned char reverse_table[256];
static int table_initialized = 0;


void build_reverse_table(void) {
    for(int i = 0 ;i <256 ; i++) {
        reverse_table[i] = INVALID;
    }
    for(int i = 0 ;i<64;i++) {
        unsigned char c = base64_table[i];
        reverse_table[c] = (unsigned char)i ;
    }
    table_initialized = 1;
}

char *base64_encode(const unsigned char *data, size_t input_len , size_t *out_len) {
    size_t encoded_len = 4*((input_len+2)/3);
    char *encoded = (char*)malloc(encoded_len+1);
    if(encoded  == NULL) {
        return NULL;
    }
    size_t i = 0; 
    size_t j = 0 ;
    while(i < input_len) {
        unsigned char byte0 = data[i] ;
        unsigned char byte1 = (i+1 < input_len) ? data[i+1] : 0;
        unsigned char byte2 = (i+2<input_len) ? data[i+2] :0 ;

        unsigned int triple = ((unsigned int)byte0 << 16 ) | ((unsigned int)byte1 << 8) | ((unsigned int) byte0);

        unsigned char index0 = (triple>>18) & 0x3F;
        unsigned char index1 = (triple>>12) & 0x3F;
        unsigned char index2 = (triple>>6) & 0x3F;
        unsigned char index3 = (triple) & 0x3F;
        
        encoded[j++] = base64_table[index0];
        encoded[j++] = base64_table[index1];
        encoded[j++] = (i+1 < input_len) ? base64_table[index2] : '=';
        encoded[j++] = (i+2 < input_len) ? base64_table[index3] : '=';
         
        i+=3;
    }
    encoded[j++] = '\0';

    if(out_len != NULL) {
        *out_len = encoded_len;
    }

    return encoded;



}

unsigned char *base64_decode(const char *encoded, size_t *out_len) {
    if(!table_initialized) {
        build_reverse_table();
    }
    size_t input_len = strlen(encoded);
    if(input_len ==0 || input_len%4 != 0 ) {
        return NULL;
    }
    size_t padding = 0;
    if(encoded[input_len - 1] == '=') padding++ ;
    if(encoded[input_len - 2] == '=') padding++;

    size_t decoded_len = (input_len /4) * 3 - padding;
    unsigned char *decoded = (unsigned char*)malloc(decoded_len > 0 ? decoded_len : 1);
    if(decoded  == NULL) {
        return NULL;
    }

    size_t i = 0;
    size_t j = 0;
    while(i < input_len) {
        unsigned char c0 = (unsigned char) encoded[i] ;
        unsigned char c1 = (unsigned char) encoded[i+1] ;
        unsigned char c2 = (unsigned char) encoded[i+2] ;
        unsigned char c3 = (unsigned char) encoded[i+3] ;

        unsigned char idx0 = reverse_table[c0];
        unsigned char idx1 = reverse_table[c1];
        unsigned char idx2 = (c2 == '=') ? 0 : reverse_table[c2];
        unsigned char idx3 = (c3 == '=') ? 0 : reverse_table[c3];

        if(idx0 == INVALID || idx1== INVALID || (c2 != '=' && idx2 == INVALID) || (c3 != '=' && idx3 == INVALID)) {
            free(decoded) ;
            return NULL;
        }

        unsigned int triple = ((unsigned int)idx0 << 18) | ((unsigned int)idx1 << 12) |
                               ((unsigned int)idx2 << 6)  |
                               ((unsigned int)idx3);

        unsigned char byte0 = (triple >> 16) & 0xFF;
        unsigned char byte1 = (triple >> 8) & 0xFF;
        unsigned char byte2 = triple & 0xFF;
 
        decoded[j++] = byte0;
        if (c2 != '=') decoded[j++] = byte1;
        if (c3 != '=') decoded[j++] = byte2;
 
        i += 4;

         

    }
    if(out_len != NULL) {
        *out_len = decoded_len; 
    }
    return decoded;

}

int main() {
    const char *input_text = "A";
    size_t enc_len;
    char *encoded = base64_encode((const unsigned char*)input_text,strlen(input_text),&enc_len);

    printf("Original : %s\n" , input_text);
    printf("Encoded: %s\n", encoded);

    size_t dec_len;
    unsigned char *decoded = base64_decode(encoded , &dec_len);
    printf("decoded: ");
    for(size_t k  = 0; k<dec_len ; k++ ){
        putchar(decoded[k]);
    }
    printf("\n");
    free(encoded);
    free(decoded);
    return 0;

}
