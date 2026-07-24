#include <stdio.h>

int main(){
    int c , next;
    while((c=getchar()) != EOF ){
        
        if(c == '"') {
             putchar(c);
            while((c=getchar())!=EOF){
                putchar(c);
                if(c == '\\') {
                    c= getchar();
                    if(c == EOF) break;
                    putchar (c);
                }
                else if(c== '"'){
                    break;
                }
            }


        }

        else if(c=='\''){
             putchar(c);
            while((c=getchar()) != EOF){
                putchar(c);
                if(c=='\\'){
                    c= getchar();
                    if(c==EOF) break;
                    putchar(c);
                }
                else if( c=='\''){
                    break;
                }
            }
        }

        else if (c == '/'){
            next = getchar();
             if(next == '/'){
                while((c= getchar()) != EOF && c!='\n');
                if(c=='\n') {
                    putchar('\n');
                }

             }
             else if(next == '*'){
                int prev  = 0;
                while((c=getchar())!=EOF){
                    if( prev =='*' && c=='/'){
                        break;
                    }
                    prev = c;
                     
                }


             }
             else{
                putchar(c);
                if(next!=EOF){
                    ungetc(next,stdin);
                }
             }

        }
        else{
            putchar(c);
        }
    }
    return 0 ;

}
