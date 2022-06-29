#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2022/06/21 TLE

int isSub(char *a, char *b, int la, int lb){
    char *ptr = a;
    ptr += la - lb;
    return(!strncmp(ptr, b, lb));

}

void insertionSort(char **words, int size){
    for (int i = 0; i < size; i++){
        int index = i;
        int len = strlen(words[i]);
        for (int j = i+1; j < size; j++){
            if (strlen(words[j]) > len){
                index = j;
                len = strlen(words[j]);
            }
        }
        char temp[8];
        strcpy(temp, words[index]);
        strcpy(words[index], words[i]);
        strcpy(words[i], temp);
    }
}

int p(char ** words, int wordsSize){ 
    int w[2001];

    int ct = 0;
    insertionSort(words, wordsSize);

    int ans = 0, go = 0;
    ans += strlen(words[0]);
    w[ct] = 0;
    ct++;
    for (int i = 1; i < wordsSize; i++){
        go = 0;
        for (int j = 0; j < ct; j++){
            if (!isSub(words[w[j]], words[i], strlen(words[w[j]]), strlen(words[i]))){
                if (j == ct-1){
                    go = 1;
                }
            }
            else
                break;
        }
        if (go){
            w[ct] = i;
            ct++;
            ans += strlen(words[i]);
        }
    }
    return ans+ct;
}

int main(){
    int size = 1;
    char ** words = malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++)
        words[i] = malloc(sizeof(char) * 8);
    // strcpy(words[2], "time");
    // strcpy(words[0], "me");
    // strcpy(words[1], "bell");
    strcpy(words[0], "t");
    
    printf("%d\n", p(words, size));
    return 0;
}