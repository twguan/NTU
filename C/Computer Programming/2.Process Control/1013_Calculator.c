#include <stdio.h>

int main(){
    float a, b;
    char c;
    scanf("%f%f %c", &a, &b, &c);
    switch (c)
    {
    case '+':
        printf("%.2f %c %.2f = %.2f", a, c, b, a + b);
        break;
    case '-':
        printf("%.2f %c %.2f = %.2f", a, c, b, a - b);
        break;
    case '*':
        printf("%.2f %c %.2f = %.2f", a, c, b, a * b);
        break;
    case '/':
        printf("%.2f %c %.2f = %.2f", a, c, b, a / b);
        break;
    }
    return 0;
}