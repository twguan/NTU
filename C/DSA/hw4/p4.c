#include <stdio.h>
#include <stdlib.h>

#define int long long

typedef struct node{
    int num;
    int start;
    int end;
    struct node *left;
    struct node *right;
}node;

node *createNode(){
    node *newNode;
    return newNode;
}

void build_tree(int arr[], node *root, int start, int end){
    if (root->start == root->end){
        root->num = arr[root->start];
        root->left = NULL;
        root->right = NULL;
        return;
    }

    int mid = (root->start + root->end) / 2;
    node *left_node = createNode();
    node *right_node = createNode();
    root->left = left_node;
    

    root->right = right_node;
    
    printf("1 ");
    // build_tree(arr, left_node);
    // build_tree(arr, right_node);
    root->num =  left_node->num + right_node->num;
}

void traverse(node *root){
    if (root == NULL)
        return;
    traverse(root->left);
    printf("%lld ", root->num);
    traverse(root->right);
}


int arr[100001];

int main(){
    int N, Q;
    scanf("%d%d", &N, &Q);

    for (int i = 1; i < N+1; i++)
        scanf("%lld", &arr[i]);

    node *root;
    root->start = 1;
    root->end = N;
    build_tree(arr, root, 1, N);

    // for (int i = 1; i < Q+1; i++){
    //     int op;
    //     scanf("%d", &op);
    //     if (op == 6){

    //     }
    // }
    printf("end\n");
    traverse(root);
    return 0;
}