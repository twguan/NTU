#include <stdio.h>

int n, tree[10000];

void inorder(int root){
    if (root > n-1)
        return;
    inorder(2 * root + 1);
    printf("%d ", tree[root]);
    inorder(2 * root + 2);
}


int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &tree[i]);
    inorder(0);
    return 0;
}