#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int ct = 0;
    char book[50], list[10][50];
    scanf("%s", book);
    book[0] = tolower(book[0]);
    scanf("%s", list[0]);
    while (strcmp(list[ct], "q")){
        ct++;
        scanf("%s", list[ct]);
    }
    for (int i = 0; i < ct; ++i){
        if (!(strcmp(book, list[i]))){
            printf("Yes %d", i+1);
            break;
        }
        if (i == ct-1)
            printf("No %d", ct);
    }
    return 0;
}