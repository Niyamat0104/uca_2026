#include<stdlib.h>
#include<stdio.h>

void url_encode(char *str,int true_length) {
	int count = 0;
	for(int i = 0; i < true_length ; i++) {
		if(str[i] == ' ') {
			count ++;
		}
	}

	int new_length = true_length + 2 * count;
	str[new_length] = '\0';
	int i = true_length - 1;
	int j = new_length - 1;
	while( i >= 0){
		if(str[i] == ' '){
			str[j] = '0';
			str[j-1] = '2';
			str[j-2] = '%';
			j-=3;
		}
		else{
			str[j] = str[i];
			j--;
		}
		i--;
	}


}

int main() {
	char str[] = "Hello World  ";
	int true_length = 11;
	url_encode (str , true_length);
	printf("After encoding the string becomes : %s\n",str);
}

