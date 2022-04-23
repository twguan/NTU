#include <stdio.h>
int subset(int num[], int size, int tag[], int i, int sums[]){
    int j, sum = 0;
    if (i == size){
        static int count = 0;
        for (j = 0; j < size; ++j){
            if(tag[j] == 1)
                sum += num[j];
        }
        sums[count] = sum;
        count++;
        return 0;
    }
    tag[i] = 0;
    subset(num, size, tag, i+1, sums);
    tag[i] = 1;
    subset(num, size, tag, i+1, sums);
}
int main(){
    int size, i, ans, k, n = 1;
    scanf("%d", &size);
    int num[size], tag[size];
    for (i = 0; i < size; ++i){
        scanf("%d", &num[i]);
        n *= 2;
    }
    int sums[n];
    subset(num, size, tag, 0, sums);
    while (scanf("%d", &k) != EOF){
        ans = 0;
        for (i = 0; i < n; ++i){
            if (sums[i] == k)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}