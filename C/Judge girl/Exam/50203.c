#include <stdio.h>

int findmax(int a, int b, int c){
    if (a >= b){
        if (a >= c)
            return 1;
        else
            return 3;
    }
    else {
        if (c >= b)
            return 3;
        else
            return 2;
    }
}

int main(){
    int w, type, col, pos1, pos2, pos3;
    scanf("%d", &w);
    int heigh[100000] = {};
    while (scanf("%d%d", &col, &type) != EOF){
            pos1 = heigh[col];
            pos2 = heigh[col+1];
            pos3 = heigh[col+2];
        if (type == 0){
            pos1--;
            int max = findmax(pos1, pos2, pos3);
            if (max == 1){
                heigh[col]++;
                heigh[col+1] = heigh[col];
                heigh[col+2] = heigh[col]-1;
            }
            else if (max == 2){
                heigh[col+1] += 2;
                heigh[col] = heigh[col+1];
                heigh[col+2] = heigh[col]-1;
            }
            else{
                heigh[col+2]++;
                heigh[col+1] = heigh[col+2]+1;
                heigh[col] = heigh[col+1];
            }
        }
        else if (type == 1){
            pos3--;
            int max = findmax(pos1, pos2, pos3);
            if (max == 1){
                heigh[col]++;
                heigh[col+1] = heigh[col]+1;
                heigh[col+2] = heigh[col]+1;
            }
            else if (max == 2){
                heigh[col+1] += 2;
                heigh[col] = heigh[col+1]-1;
                heigh[col+2] = heigh[col+1];
            }
            else{
                heigh[col+2]++;
                heigh[col+1] = heigh[col+2];
                heigh[col] = heigh[col+1]-1;
            }
        }
        else if (type == 2){
            int max = findmax(pos1, pos2, pos3);
            if (max == 1){
                heigh[col]++;
                heigh[col+1] = heigh[col]+1;
                heigh[col+2] = heigh[col];
            }
            else if (max == 2){
                heigh[col+1] += 2;
                heigh[col] = heigh[col+1]-1;
                heigh[col+2] = heigh[col+1]-1;
            }
            else{
                heigh[col+2]++;
                heigh[col+1] = heigh[col+2]+1;
                heigh[col] = heigh[col+2];
            }
        }
        else if (type == 3){
            pos1--;
            pos3--;
            int max = findmax(pos1, pos2, pos3);
            if (max == 1){
                heigh[col]++;
                heigh[col+1] = heigh[col];
                heigh[col+2] = heigh[col];
            }
            else if (max == 2){
                heigh[col+1] += 2;
                heigh[col] = heigh[col+1];
                heigh[col+2] = heigh[col+1];
            }
            else{
                heigh[col+2]++;
                heigh[col+1] = heigh[col+2];
                heigh[col] = heigh[col+2];
            }
        }
    }
    for (int i = 0; i < w; i++)
        printf("%d ", heigh[i]);
    return 0;
}