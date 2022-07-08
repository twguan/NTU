#include <stdio.h>                                                                              

// You can write your own functions here. 
 
void printnum(int num){
    for (int i = 0; i < 8; i++){
        printf("%d", num % 2);
        num = num >> 1;
    }
} 

void printBlock(unsigned long long int *block) {
    unsigned long long int num = *block;
    for (int i = 0; i < 8; i++){
        printnum(num & 511);
        printf("\n");
        num = num >> 8;
    }
}
 
void initialize(unsigned long long int *block, int row, int column, int size) {
    for (int i = 0; i < 8 ; i++){
        for (int j = 0; j < 8; j++){
            if (8-column-size <= j && j < 8-column && 8-row-size <= i && i < 8-row)
                *block += 1;
            if (i == 7 && j == 7)
                continue;
            *block = *block << 1;
        }
    }
}
 
int moveLeft(unsigned long long int *block) {
    unsigned long long int side = 1;
    for (int i = 0; i < 7; i++){
        side = side << 8;
        side += 1;
    }
    if (*block & side)
        return 0;
    else
        *block = *block >> 1;
    return 1; 
}
 
int moveRight(unsigned long long int *block) {
    unsigned long long int side = 128;
    for (int i = 0; i < 7; i++){
        side = side << 8;
        side += 128;
    }
    if (*block & side)
        return 0;
    else
        *block = *block << 1;
    return 1; 
}
 
int moveUp(unsigned long long int *block) {
    unsigned long long int side = 255;
    if (*block & side)
        return 0;
    else
        *block = *block >> 8;
    return 1; 
}
 
int moveDown(unsigned long long int *block) {
    unsigned long long int side = 255;
    side = side << 56;
    if (*block & side)
        return 0; 
    else
        *block = *block << 8;
    return 1;
}