#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

typedef struct node{
    int value;
    struct node *next;
}Node;

int isEmpty(Node *n) {
    return n == NULL;
}
int size (Node *n) {
    Node* temp = n;
    int count  = 0;
    while(temp != NULL){
        count++;
        temp = temp ->next;
    }
    return count;
}

void push(Node **head , int key ) {
    printf("inserting %d\n", key);
    Node *node = malloc(sizeof(Node));
    node->value = key;
     
    if(*head == NULL) {
        *head = node;
        return ;
    }
    node->next = *head;
    *head = node;
     
}


void pop(Node **head) {
    if(*head == NULL) {
        printf("No elements to delete !!");
    }
    else{
        Node* nextHead = (*head)->next;
        Node* todelete = *head;
        *head = nextHead;
        free(todelete);


    }
}
void print(Node *n) {
    Node* temp = n;
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *stack = NULL;
    
    push(&stack,10);
    push(&stack,20);
    print(stack);
    pop(&stack);
    print(stack);
}