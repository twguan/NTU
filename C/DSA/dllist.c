#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

void *insert(Node **head, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = *head;
    newNode->next = NULL;
    if (*head != NULL){
        (*head)->next = newNode;
    }
    (*head) = newNode;
}

void traverse(Node *head){
    while (head != NULL){
        printf("data: %d -> ", head->data);
        head = head->next;
    }
}

void traverseBack(Node *tail){
    while (tail != NULL){
        printf("data: %d -> ", tail->data);
        tail = tail->prev;
    }
}

int main(){
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    Node *tail = head;
    for (int i = 1; i < 5; i++)
        insert(&tail, i);
    traverse(head);
    printf("\n");
    traverseBack(tail);
}