#include <stdio.h>

typedef struct pokemon{
    char Name[128];
    int Lv;
    int Hp;
}Pokemon;

int main(){
    int n, go = 1;
    Pokemon book[3];
    for (int i = 0; i < 3; i++)
        scanf("%s%d%d", &book[i].Name, &book[i].Lv, &book[i].Hp);
    scanf("%d", &n);
    for (int i = 0; i < 3; i++){
        if (book[i].Lv >= n){
            printf("Name: %s\n", book[i].Name);
            printf("Lv: %d\n", book[i].Lv);
            printf("HP: %d\n\n", book[i].Hp);
            go = 0;
        }
    }
    if (go)
        printf("not found");
    return 0;
}