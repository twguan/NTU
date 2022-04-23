#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    char num[10000] = "\0";
    while (scanf("%s", num) != EOF){
    int n3 = 0, n7 = 0, n11 = 0, ct = 0, go = 1, go7 = 1;
        for (int i = strlen(num); i > 0; --i){
            n3 += num[i-1]-'0';
            if (go){
                go = 0;
                n11 += num[i-1]-'0';
            }
            else{
                go = 1;
                n11 -= num[i-1]-'0';
            }
            if (go7){
                n7 += (num[i-1]-'0') * pow(10, ct);
                ct++;
                if (ct == 3){
                    go7 = 0;
                    ct = 0;
                }
            }
            else {
                n7 -= (num[i-1]-'0') * pow(10, ct);
                ct++;
                if (ct == 3){
                    go7 = 1;
                    ct = 0;
                }
            }
        }
        if(n3 % 3)
            printf("NO ");
        else
            printf("Yes ");
        if (n7 % 7)
            printf("N0 ");
        else
            printf("Yee ");
        if (n11 % 11)
            printf("No\n");
        else
            printf("Yeah\n");
    }
    return 0;
}