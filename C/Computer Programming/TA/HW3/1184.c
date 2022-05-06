#include <stdio.h>

int main(){
    char filename[16];
    int temp, ct = 0;
    double sum = 0;

    scanf("%s", filename);
    FILE *f = fopen(filename, "r");
    filename[0] = 'w';
    FILE *out = fopen(filename, "w");
    while (1){
        if(feof(f))
            break;
        fscanf(f, "%d ", &temp);
        ct++;
        fprintf(out, "%d ", temp);
        sum += temp;
    }
    fprintf(out, "\n%.0f\n%.2f", sum, sum/ct);
    printf("%.0f\n", sum);
    printf("%.2f", sum/ct);
    fclose(f);
    fclose(out);
    return 0;
}