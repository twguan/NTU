#include <stdio.h>
 
int snake(int *ptr, int *row, int *column) {
    int ct = 0;
    while(*ptr == ct){
        ct++;
        ptr++;
    }
    *column = ct;
    *row = 1;
    int correct = ct-1;
    ptr--;
    int first = 1;
    // printf("row:%d, ptr:%d, cr:%d\n", *row, *ptr, correct);
    while(correct == *ptr){
        if (ct == *column || ct == 1){
            if (first){
                correct += *column;
                first = 0;
            }
            else{
                *row += 1;
                first = 1;
                if (*row % 2){
                    correct++;
                    ct++;
                }
                else{
                    correct--;
                    ct--;
                }
                
            }
        }
        else if (*row % 2){
            correct++;
            ct++;
        }
        else{
            correct--;
            ct--;            
        }
        ptr++;
    }

    if (*ptr){
        *column = ct-1;
        *row -= 1;
        return 0;
    }
    else
        return 1;
}

int main(void)
{
    int trav[1024] = {0}, row = 0, column = 0, res = 0;
    scanf("%d %d", &trav[0], &trav[1]);
    for(int i = 1; trav[i]; i++)
      scanf("%d", &trav[i + 1]);
    res = snake(trav, &row, &column);
    if(res) printf("%d %d\n", row, column);
    else printf("err %d %d\n", row, column);
    return 0;
}