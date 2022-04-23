#include <stdio.h>
#include<ctype.h>
#include <string.h>
 
int main(){
    int txtct = 0, pyct = 0, ct = 1, post[10], posp[10];
    char input[30] = "\0", txt[10][30] = {"\0"}, py[10][30] = {"\0"};
    char p[] = "py", t[] = ".txt";
    char* ptrp, * ptrt;
    scanf("%s", input);
    while (strcmp(input, "-1")){
        ptrt = strstr(input, t);
        ptrp = strstr(input, p);
        if (ptrp){
            posp[pyct] = ct;
            for (int i = 0; i < strlen(input)-2; ++i)
                input[i] = toupper(input[i]);
            strcpy(py[pyct], input);
            pyct++;
        }
        else if(ptrt){
            post[txtct] = ct;
            input[0] = toupper(input[0]);
            strcpy(txt[txtct], input);
            txtct++;
        }
        ct++;
        scanf("%s", input);
    }
    if (txtct){
        printf("['S%02d_%s'", post[0], txt[0]);
        for (int i = 1; i < txtct; ++i)
            printf(", 'S%02d_%s'", post[i], txt[i]);
        printf("]");
    }
    if (pyct){
        printf("\n['S%02d_%s'", posp[0], py[0]);
        for (int i = 1; i < pyct; ++i)
            printf(", 'S%02d_%s'", posp[i], py[i]);
        printf("]");
    }
    printf("\n");
    return 0;
}
