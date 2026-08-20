#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;
 
void push(char ch) {
    if(top == MAX-1){
        printf("STack Oveflow");
    }
    stack[++top] = ch;
}

char pop() {
    if(top == -1) {
        printf("stack underflow\n");
        return '\0';
    }
    return stack[top--];
}
int isEmpty(){
    if(top == -1) {
        return 1;
 }

char peek() {
    if(top == -1) {
        return '\0';
    }
    return stack[top];
}

int isMatching(char open , char close) {
    if(open == '{' && close =='}' ) {
        return 1;
    }
    if(open == '[' && close ==']' ) {
        return 1;
    }
    if(open == '(' && close ==')' ) {
        return 1;
    }
    return 0;
}

int areBraketsBalanced(char expr[] , int n) {

    for(int i = 0 ; i < n ; i++) {
        if(expr[i] == '{' || expr[i] == '[' || expr[i] == '(') {
            push(expr[i]);
        }
        else if(expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if(isEmpty() == 1) {
                return 0;
            }
            char currTop = pop();
            if(!isMatching(currTop,expr[i])) {
                return 0;
            }
        }
    }

    return isEmpty();
     


    

}


int main() {

    char expr[] = "[()";
    if(areBraketsBalanced(expr,3)){
        printf("true\n");
    }
    else{
        printf("false\n");
    }


}