#include <stdio.h>

int main(){
    int n, ct = 0;
    char filename[32];
    char input[32];
    scanf("%d%s", &n, filename);
    FILE *f = fopen(filename, "r");
    while(1){
        if (feof(f))
            break;
        fscanf(f, "%s ", input);
        ct++;
        if (ct == n){
            ct = 0;
            continue;
        }
        printf("%s ", input);
    }
    return 0;
}