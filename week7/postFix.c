#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push (int val) {
    if(top == MAX-1) {
        printf(" stack Over flow\n");
        return;

    }
    stack[++top] = val;
}

int pop() {
    if(top == -1) {
        printf("stack Underflow \n");
        return -1;
    }
    return stack[top--];
}

int isEmpty() {
    if(top == -1){
        return 1;
    }
    return 0;
}

int ans (int n1 , int n2 , char op) {
    if(op == '+'){
        return n1+n2;
    }
    else if(op == '-') {
        return n1-n2;
    }
    else if(op == '*'){
        return n1*n2;
    }
    else if(op == '/') {
        return n1/n2;
    }
    else{
        return 0;
    }
    
}

int postFix(char expr[]) {
    
    char *token = strtok(expr, " ");

    while (token != NULL) {
        if(isdigit((token[0]))){
            push((token[0])-'0');
        }
        else{
            int a = pop();
            int b = pop();
            int result = ans(b,a,(token[0]));
            push(result);
        }
        token = strtok(NULL, " ");

    }
    return pop();

}

int main() {
    char expr[] = "2 3 1 * + 9 -";
    int result = postFix(expr);
    printf("%d\n",result);



}