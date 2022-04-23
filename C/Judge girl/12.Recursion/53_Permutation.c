#include <stdio.h>
void perm(int arr[], int n, int sarr[], int size){
    int i, j;
    int narr[n-1];
    if (n == 1){
        sarr[size-n] = arr[0];
        for (i = 0; i < size; ++i)
            printf("%d ", sarr[i]);
        printf("\n");
        return;
    }
    for (i = 0; i < n; ++i){// chose i
        int conflict = 0;
        for (j = 0; j < n; ++j){ //put in narr
            if (j == i){
                conflict = 1;
                sarr[size-n] = arr[j];
                continue;
            }
            if (!conflict)
                narr[j] = arr[j];
            else 
                narr[j-1] = arr[j];
        }
        perm(narr, n-1, sarr, size);
    }
}
int main(){
    int size, i, j, min;
    scanf("%d", &size);
    int array[size], sarray[size];
    for (i = 0; i < size; ++i)
        scanf("%d", &array[i]);
    for (i = 0; i < size; ++i){
        for (j = i + 1; j < size; ++j){
            if (array[j] < array[i]){
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    perm(array, size, sarray, size);
    return 0;
}