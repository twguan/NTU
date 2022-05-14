#include <stdio.h>
#include <string.h>

#define max 10000001

char input[max] = "";
char rever_str[max] = "";
char concat_str[2*max+1] = "";
char concat_str2[2*max+1] = "";
int pf[2*max+1] = {0};      //prefix function
int pf2[2*max+1] = {0};

void makePrefix(int len, int *pf, char *str){
    int k = 0;
    pf[0] = 0;
    for(int q = 1; q < len; q++) {
        if(str[q] == str[k]){
            k++;
            pf[q] = k;
        }
        else{
            if(k != 0){
                k = pf[k-1];
                q--;
            }
            else{
                pf[k] = 0;
            }
        }
    }
}


int main(){
    int len = 0;
    char c;
    while((c = getchar()) != EOF){
        if (c == '\n')
            continue;
        input[len] = c;
        concat_str[len] = c;
        len++;
    }
    concat_str[len] = ' ';
    int ct = len+1;
    for (int i = 0; i < len; i++){
        // rever_str[i] = input[len-1-i];
        concat_str2[i] = input[len-1-i];
        concat_str[ct] = input[len-1-i];
        ct++;
    }

    concat_str2[len] = ' ';
    strcat(concat_str2, input);
    makePrefix(2*len+1, pf, concat_str);
    makePrefix(2*len+1, pf2, concat_str2);
    // print the concat function and prefix function

    // printf("%s\n", concat_str2);
    // for (int i = 0; i < 2*len+1; i++)
    //     printf("%d", pf2[i]);
    // printf("\n");

    
    int front_num = len - pf[2*len];
    int back_num = len - pf2[2*len];
    if (front_num <= back_num)
        printf("%d\n", front_num);
    else 
        printf("%d\n", back_num);

    if (front_num <= back_num){
        for (int i = 0; i < front_num; i++)
            printf("%c", input[len-1-i]);
        printf("%s", input);
    }
    if (front_num == back_num)
        printf("\n");
    if (back_num <= front_num && (back_num != 0)){
        printf("%s", input);
        for (int i = 0; i < back_num; i++)
            printf("%c", input[len-1-i]);
    }
    return 0;
}