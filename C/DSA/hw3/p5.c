#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node{
    long long key;    // Rabin-Karp value
    int index;
}node;

int cmp( const void *a ,const void *b){
    return (*(node *)a).key >= (*(node *)b).key ? 1 : -1;
}

long long hash(char c){
    return (long long)(c - ' ');
}

long long comb2(long long n){
    if (n < 2)
        return 0;
    else
        return n*(n-1)/2;
}

int InList(long long target, long long *list, int len){
    int go = 0;
    for (int i = 0; i < len; i++){
        if (list[i] == target){
            go = 1;
            break;
        }
    }
    return go;
}

int main(){
    int k, l, flag;
    char input;

    scanf("%d%d%d", &k, &l, &flag);

    node *magic = (node *)malloc(sizeof(node) * k);
    node **similar = (node **)malloc(sizeof(node *) * l);
    long long *origin = (long long*)malloc(sizeof(long long) * k);
    for (int i = 0; i < l; i++)
        similar[i] = (node *)malloc(sizeof(node) * k);

    long long d = 0x7E - 0x21 + 1;  // d = 94
    long long q = LLONG_MAX / d + 1;
    long long h = 1;

    for (int i = 0; i < l; i++)
        h *= d;
    for (int i = 0; i < k; i++){
        magic[i].index = i;
        magic[i].key = 0;
        for (int j = 0; j < l; j++)
            similar[j][i].key = 0;
        for (int j = 0; j < l; j++){
            scanf(" %c", &input);
            long long hash_num = hash(input);
            magic[i].key = (d*magic[i].key + hash_num) % q;
            similar[j][i].index = i;
            for (int m = 0; m < l; m++)
                if (j != m)
                     similar[m][i].key = (d*similar[m][i].key + hash_num) % q;        
        }
        origin[i] = magic[i].key;
    }
    
    qsort(magic, k, sizeof(node), cmp);
    for (int i = 0; i < l; i++)
        qsort(similar[i], k, sizeof(node), cmp);

    // print the rk value abd its index

    // printf("magic\n");
    // for (int i = 0; i < k; i++)
    //     printf("[%d]key: %lld\n", magic[i].index, magic[i].key);
    // printf("\n");
    // for (int i = 0; i < k; i++)
    //     printf("origin hash value: %lld\n", origin[i]);
    // for(int j = 0; j < l; j++){
    //     for (int i = 0; i < k; i++)
    //         printf("[%d]key: %lld\n", similar[j][i].index, similar[j][i].key);
    //     printf("\n");
    // }


    if (flag){  // flag = 1
        long long ans = 0;
        long long ct = 1;

        // count # similar pairs
        for (int j = 0; j < l; j++){
            ct = 1;
            for (int i = 0; i < k; i++){
                if (i == k)
                    ans += comb2(ct);
                else if(similar[j][i].key == similar[j][i+1].key)   // if they are similar, check if they are the same
                    ct++;
                else{
                    ans += comb2(ct);
                    ct = 1;
                }
            }
        }
        // count # same pairs
        ct = 1;
        for (int i = 0; i < k; i++){
            if (i == k)
                ans -= comb2(ct)*(l-1);
            else if (magic[i].key == magic[i+1].key){
                ct++;
            }
            else{
                ans -= comb2(ct)*(l-1);
                ct = 1;
            }
        }
        if (ans)
            printf("Yes\n%lld", ans);
        else
            printf("No");
    }

    else{   // flag = 0
        int go = 1;
        for (int i = 0; i < k-1; i++){
            if(!go)
                break;
            if (magic[i].key == magic[i+1].key){
                printf("Yes\n%d %d", magic[i].index, magic[i+1].index);
                go = 0;
            }
        }
        if(go){
            for (int j = 0; j < l; j++){
                if(!go)
                    break;
                for (int i = 0; i < k-1; i++){
                    if(!go)
                        break;
                    if (similar[j][i].key == similar[j][i+1].key){
                        printf("Yes\n%d %d", similar[j][i].index, similar[j][i+1].index);
                        go = 0;
                    }
                }
            }
        }
        if (go)
            printf("No");
    }

    free(magic);
    for(int i = 0; i < l; i++)
        free(similar[i]);
    free(similar);
    return 0;
}