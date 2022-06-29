#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        char *temp;
        temp = words[index];
        words[index] = words[i];
        words[i] = temp;
    }
}


int main(){
    int size = 3;
    char ** words = malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++)
        words[i] = malloc(sizeof(char) * 8);
    strcpy(words[1], "me");
    strcpy(words[0], "time");
    strcpy(words[2], "bel");

    insertionSort(words, size);

    for (int i = 0; i < size; i++)
        printf("%s\n", words[i]);
    return 0;
}