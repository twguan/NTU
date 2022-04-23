#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
typedef struct Node{
    int data;
    struct Node *npx;
}Node;

Node *XOR (Node *a, Node *b){
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

void insert(Node **head_ref, int data){
    Node *new_node = (Node *) malloc (sizeof (Node) );
    new_node->data = data;
    new_node->npx = *head_ref;

    if (*head_ref != NULL){
        (*head_ref)->npx = XOR(new_node, (*head_ref)->npx);
    }

    *head_ref = new_node;
}

void *deleteHead(Node **head){
    if (*head == NULL)
        printf("List is empty\n");
    else {
        Node *temp = *head;
        *head = XOR(NULL, temp->npx);
        if (*head != NULL){
            (*head)->npx = XOR(NULL, XOR(temp, (*head)->npx));
        }
        free(temp);
    }
    // return *head;
}

void printList (Node *head){
    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    printf ("Following are the nodes of Linked List: \n");

    while (curr != NULL){
        printf ("%d ", curr->data);
        next = XOR (prev, curr->npx);
        prev = curr;
        curr = next;
    }
}

int main (){
    /* Create following Doubly Linked List
    head-->40<-->30<-->20<-->10 */
    Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printList (head);
    printf("\n");
    deleteHead(&head);
    printList(head);
    return (0);
}