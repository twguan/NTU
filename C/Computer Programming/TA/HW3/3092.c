#include <stdio.h>
#include <string.h>

int main(){
    int temp, ct = 0;
    double sum = 0;
    char input[32];
    char filename[32] = "../app/";
    scanf("%s", input);
    strcat(filename, input);
    FILE *f = fopen(filename, "r");
    while(1){
        char chef[64] = "chef ";
        fscanf(f, "%s", input);
        if(feof(f))
            break;
        fscanf(f, "%d", &temp);
        strcat(chef, input);
        printf("%s %d\n", chef, temp);
        sum += temp;
        ct++;
    }
    printf("Total: %.0f\nAvg: %.2f", sum, sum/ct);
    fclose(f);
    return 0;
}