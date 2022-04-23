#include <stdio.h>

int main(){
    int height, weight;
    double bmi;
    scanf("%d%d", &height, &weight);
    bmi = weight * 10000.0 / height / height;
    printf("%.2f\n", bmi);
    if (bmi < 18.5)
        printf("Underweight");
    else if (bmi < 24)
        printf("Normal");
    else if (bmi < 27)
        printf("Overweight");
    else if (bmi < 30)
        printf("Obese Class I");
    else if (bmi < 35)
        printf("Obese Class II");
    else
        printf("Obese Class III");
}