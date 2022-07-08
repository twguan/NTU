#include <stdio.h>
#include<ctype.h>
#include <string.h>
 
int main(){
    int a[3] = {0, 1, 2};
    printf("%d", *(a+1));
    return 0;
}
