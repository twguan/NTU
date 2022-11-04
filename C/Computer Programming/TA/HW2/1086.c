#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n;
    char c1, c2, s1[256], s2[256];
    double f;
    scanf("%d %c %lf ", &n, &c1, &f);
    gets(s1);
    scanf("%c ", &c2);
    gets(s2);

    printf("%.2f\n%c %d\n%c %d\n", n+f, (int)c1+n, (int)c1+n, (int)(c2+(int)f), (int)(c2+(int)f));
    for (int i = 0; i < strlen(s1); ++i)
        printf("%c", tolower(s1[i]));
    printf("\n");
    for (int i = 0; i < strlen(s2); ++i)
        printf("%c", toupper(s2[i]));

  return 0;
}