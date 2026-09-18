#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

Node *intersectionOfLists(Node *head1,Node *head2){
    Node* head = malloc(sizeof(Node));
     
    head->value = -1;
    Node* tail = head;
     
    while(head1!= NULL &&  head2!= NULL) {
        if(head1->value == head2->value) {
             
                Node* curr = malloc(sizeof(Node));
                curr->value = head1->value;
                tail->next = curr;
                tail = tail->next;
                head1 = head1->next;
                head2= head2->next;
            
        }
        else if (head1->value < head2->value) {
            head1 = head1->next;

        }
        else{
            head2= head2->next;
        }
    }

    return head->next;

     
    


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
    head1->value = 1;

    Node* node1 = malloc(sizeof(Node));
    node1->value = 2;
    Node* node2 = malloc(sizeof(Node));
    node2->value = 3;
    Node* node3 = malloc(sizeof(Node));
    node3->value = 4;
    Node* node4 = malloc(sizeof(Node));
    node4->value = 6;
     
    head1->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
     
    printf("Printing first list \n");
    print(head1);

    Node* head2 = malloc(sizeof(Node));
    head2->value = 2;

    Node* node11 = malloc(sizeof(Node));
    node11->value = 4;
    Node* node22 = malloc(sizeof(Node));
    node22->value = 6;
    Node* node33 = malloc(sizeof(Node));
    node33->value = 8;
     
    
    head2->next = node11;
    node11->next = node22;
    node22->next = node33;
     
    printf("Printing Second list \n");
    print(head2);

    Node* result = intersectionOfLists(head1,head2);
    printf("The intersection of both the lists \n");
    print(result);



}