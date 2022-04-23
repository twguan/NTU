#include <stdio.h>
int meterial(int formula[3][3], int A, int B, int C){
    if (A == 0 && B == 0 && C == 0)
        return 1;
    if (A < 0 || B < 0 || C < 0)
        return 0;
    return (meterial(formula, (A-formula[0][0]), (B-formula[0][1]), (C-formula[0][2])) + meterial(formula, (A-formula[1][0]), (B-formula[1][1]), (C-formula[1][2])) + meterial(formula, (A-formula[2][0]), (B-formula[2][1]), (C-formula[2][2])));
}
void loop(int formula[3][3]){
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    if (meterial(formula, A, B, C)){
        printf("yes\n");
        return;
    }
    else{
        printf("no\n");
        return;
    }
}
void recrusion(int n, int arr[3][3]){
    if (!n)
        return;
    loop(arr);
    return (recrusion(n-1, arr));
}
int main(){
    int formula[3][3];
    int n;
    scanf("%d%d%d", &formula[0][0], &formula[0][1], &formula[0][2]);
    scanf("%d%d%d", &formula[1][0], &formula[1][1], &formula[1][2]);
    scanf("%d%d%d", &formula[2][0], &formula[2][1], &formula[2][2]);
    scanf("%d", &n);
    recrusion(n, formula);
    return 0;
}    