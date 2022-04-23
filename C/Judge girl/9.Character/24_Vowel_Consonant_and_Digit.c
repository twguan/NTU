#include <stdio.h>
#include <ctype.h>

int main(){
    char c;
    int di = 0, al = 0, v = 0, co = 0;
    while (scanf("%c", &c) != EOF){
        if (isdigit(c))
            di++;
        if (isalpha(c)){
            al++;
            c = toupper(c);
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                v++;
            else 
                co++;
        }
    }
    printf("%d %d %d %d", di, al, v, co);
    return 0;
}