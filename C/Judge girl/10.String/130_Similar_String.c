#include <stdio.h>
#include <ctype.h>
#include <string.h>
void check1(char s1[], char s2[], int i);
void check(char s1[], char s2[], int i);
int main(){
    int n, i, j;
    scanf("%d", &n);
    for (j = 0; j < n; ++j){
        char s1[80], s2[80];
        scanf("%s", s1);
        scanf("%s", s2);
        if (!(strcmp(s1, s2)))
            printf("yes\n");
        else if (strlen(s1) == strlen(s2)) {
            for (i = 0; i < strlen(s1); ++i){
                if (s1[i] != s2[i]) { //check i, i+1
                    if (s1[i] == s2[i+1] && s1[i+1] == s2[i]) {
                        if (i == strlen(s1)-2){
                            printf("yes\n");
                            break;
                        }
                        check1(s1, s2, i);
                        break;
                    }
                    else{
                        printf("no\n");
                        break;
                    }    
                }
            }
        }
        else {
            int a = strlen(s1);
            if (a < strlen(s2))
                a = strlen(s2);
            for (i = 0; i < a; ++i) {
                if (s1[i] != s2[i]) {
                    if (strlen(s1) == a) {
                        check(s1, s2, i);
                        break;
                    }
                    else {
                        check(s2, s1, i);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
void check1(char s1[], char s2[], int i){
    i += 2;
    for (i; i < strlen(s1); ++i){
        if (s1[i] != s2[i]){
            printf("no\n");
            break;
        }
        if (i == strlen(s1)-1)
            printf("yes\n");
    }
}
void check(char s1[], char s2[], int i){
    for (i; i < strlen(s1); ++i) {
        if (s1[i+1] != s2[i]) {
            printf("no\n");
            break;
        }
        if (i == strlen(s1)-1)
            printf("yes\n");
    }
}