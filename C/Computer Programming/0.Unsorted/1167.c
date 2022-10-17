#include <stdio.h>

int ing[3][3], a, b, c;

int isempty(int a, int b, int c){
    if (a==0 && b==0 && c==0)
        return 1;
    if (a < 0 || b < 0 || c < 0)
        return 0;
    return isempty(a-ing[0][0], b-ing[0][1], c-ing[0][2]) + isempty(a-ing[1][0], b-ing[1][1], c-ing[1][2]) + isempty(a-ing[2][0], b-ing[2][1], c-ing[2][2]);
    
}

void scan(int n){
    if (!n)
        return;
    scanf("%d%d%d", &a, &b, &c);
    if (isempty(a, b, c))
        printf("yes\n");
    else
        printf("no\n");
    scan(n-1);
}

int main(){
    int n;
    scanf("%d%d%d", &ing[0][0], &ing[0][1], &ing[0][2]);
    scanf("%d%d%d", &ing[1][0], &ing[1][1], &ing[1][2]);
    scanf("%d%d%d", &ing[2][0], &ing[2][1], &ing[2][2]);

    scanf("%d", &n);
    scan(n);
    return 0;
}