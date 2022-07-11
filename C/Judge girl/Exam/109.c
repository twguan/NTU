#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

int stack[1001], ct = 0;

void print_all_paths(struct node *root){
    stack[ct++] = root->data;
    if (root->left)
        print_all_paths(root->left);
    if (root->right)
        print_all_paths(root->right);
    if (!(root->left || root->right)){
        for (int i = 0; i < ct; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
    ct--;
}
 
struct node *insert_bs_tree(struct node *root, int data)
{
    struct node *current;
    if (root == NULL)
    {
        current = (struct node *)malloc(sizeof(struct node));
        assert(current != NULL);
        current->data = data;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
 
    if (data < root->data)
        root->left = insert_bs_tree(root->left, data);
    else
        root->right = insert_bs_tree(root->right, data);
    return root;
}
 
int main(void)
{
    int n;
    struct node *root = NULL;
 
    while (scanf("%d", &n) != EOF)
        root = insert_bs_tree(root, n);
 
    print_all_paths(root);
}