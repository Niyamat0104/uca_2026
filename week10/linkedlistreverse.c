#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

Node *reverseLinkedList(Node *head) {
    if(head->next == NULL) return head;
    Node* h1 = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return h1;
    


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
    Node* head = malloc(sizeof(Node));
    head->value = 10;

    Node* node1 = malloc(sizeof(Node));
    node1->value = 20;
    Node* node2 = malloc(sizeof(Node));
    node2->value = 30;
    Node* node3 = malloc(sizeof(Node));
    node3->value = 40;
    Node* node4 = malloc(sizeof(Node));
    node4->value = 50;
    Node* node5 = malloc(sizeof(Node));
    node5->value = 60;
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    print(head);
    Node* newHead = reverseLinkedList(head);
    print(newHead);



}