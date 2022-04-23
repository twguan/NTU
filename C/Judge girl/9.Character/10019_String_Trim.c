#include <stdio.h>
#include <ctype.h>

int main(){
    char s[100], input;
    int size = 0, i;
    input = getchar();
    while (input != '\n'){
        s[size] = input;
        size++;
        input = getchar();
    }
    for (i = 0; i < size; ++i){
        if ( !(isspace(s[i])))
            break;
    }
    for (size; size > i; --size){
        if ( !(isspace(s[size-1])))
            break;
    }
    for (i; i < size; ++i)
        printf("%c", s[i]);
    return 0;
}
