#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

int getLen(Node *head){
    Node* temp = head;
    int count  = 0 ;
    while(temp != NULL){
       count++;
       temp = temp->next;
    }
    return count;
}

int searchLinkedList(Node* head1,Node* head2){
    int len1 = getLen(head1);
    Node *first = head1;
    Node *second = head2;
    if (head1 == NULL) {
        return 1;
    }
    
    while(second!= NULL) {
        if(first->value == second->value) {
            int count = 0;
            while(first != NULL && second!= NULL) {
                if(first->value  != second->value) {
                     break;
                    
                }
                
                first=first->next;
                second = second->next;
            }
            if(first == NULL){
                return 1;
            }
        }
        
        second = second->next;
    }


    return -1;

     
    


}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head1 = malloc(sizeof(Node));
    head1->value = 10;

    Node* node1 = malloc(sizeof(Node));
    node1->value = 20;
     
     
    head1->next = node1;
     
     
    printf("Printing first list \n");
    print(head1);

    Node* head2 = malloc(sizeof(Node));
    head2->value = 5;

    Node* node11 = malloc(sizeof(Node));
    node11->value = 10;
    Node* node22 = malloc(sizeof(Node));
    node22->value = 20;
     
     
    
    head2->next = node11;
    node11->next = node22;
     
     
    printf("Printing Second list \n");
    print(head2);

    int result = searchLinkedList(head1,head2);
    if(result == -1) {
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    
    



}