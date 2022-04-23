#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char ip[20][30], name[30];
    scanf("%d", &n);
    for (int i = 0; i < 20; ++i)
        scanf("%s", ip[i]);
    for (int i = 0; i < 5; ++i){
        scanf(" %s", &name);
        for (int j = 0; j < 20; j+=2){
            if (!(strcmp(name, ip[j]))){
                printf("%s\n", ip[j+1]);
                break;
            }
        }
    }
    return 0;
}