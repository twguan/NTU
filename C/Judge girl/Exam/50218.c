# include<stdio.h>
# include<stdlib.h>
# include<assert.h>

struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
};
 
struct list {
    struct treenode *head;
    struct treenode *tail;
};
 
typedef struct treenode TreeNode;
typedef struct list List;

List l;

List treeToListFunc(TreeNode * root){
    // if (root){
    //     TreeNode *right = root->right;
    //     TreeNode *left = root->left;
    //     root->right = NULL;
    //     if (root->value % 2){
    //         treeToListFunc(right);
    //         treeToListFunc(left);
    //     }
    //     else{
    //         treeToListFunc(left);
    //         treeToListFunc(right);
    //     }
    // }
    if (root){
        l.head = root;
        root->right = NULL;
        treeToListFunc(root->left);
    }
    return l;
}

TreeNode *buildTree(int **values, TreeNode **roots) {
    int val;
    scanf("%d", &val);
    if(val == 0) return NULL;
    **values = val;
    TreeNode *now = *roots;
    (*values)++; (*roots)++;
    now -> value = val;
    now -> left  = buildTree(values, roots);
    now -> right = buildTree(values, roots);
    return now;
}
 
int main(void) {
    int size;
    scanf("%d\n", &size);
    TreeNode * root = (TreeNode*)calloc(size, sizeof(TreeNode));
 
    int valueRecord[size];
    int *vptr = valueRecord;
    TreeNode *nptr = root;
 
    root = buildTree(&vptr, &nptr);
 
    List ans = treeToListFunc(root);
 
    TreeNode * node = ans.head;
    TreeNode * firstAddr = &root[0];
    TreeNode * lastAddr = &root[size];
    for(; node != NULL; node = node -> left) {
        if (node -> right != NULL) {
            printf("Right node should be null\n");
            break;
        }
        if (firstAddr > node || lastAddr <= node) {
            printf("Memory address out of bound\n");
            break;
        }
        int counter = node - firstAddr;
        if (node -> value != valueRecord[counter]) {
            printf("You can't modify the value in the given treeNode\n");
            break;
        }
        printf("%d ", node -> value);
    }
 
     free(root);
    return 0;
}