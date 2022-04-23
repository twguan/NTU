#include <stdio.h>
#include <stdlib.h>     // malloc / free
#include <memory.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;

void *insert(Node **ptr, int data){
    (*ptr)->next = (Node *)malloc(sizeof(Node));
    *ptr = (*ptr)->next;
    (*ptr)->data = data;
    (*ptr)->next = NULL;
}

void traverse(Node *head){
    while(head != NULL){
        printf("data: %d -> ", head->data);
        head = head->next;
    }
}

int main(){
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 10;
    head->next = NULL;
    Node *ptr = head;
    for (int i = 2; i <= 5; i++){
        insert(&ptr, i*10);
    }
    traverse(head);
    return 0;
}