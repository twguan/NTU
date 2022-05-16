#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node{
    unsigned long long key;    // Rabin-Karp value
    int index;
}node;

int cmp( const void *a ,const void *b){
    if ((*(node *)a).key >= (*(node *)b).key)
        return 1;
    else
        return -1;
    // return (*(node *)a).key >= (*(node *)b).key ? 1 : -1;
}

unsigned long long hash(char c){
    return (unsigned long long)(c - ' ');
}

unsigned long long comb2(unsigned long long n){
    if (n < 2)
        return 0;
    else
        return n*(n-1)/2;
}

int main(){
    int k, l, flag;
    char input;

    scanf("%d%d%d", &k, &l, &flag);

    node *magic = (node *)malloc(sizeof(node) * k);
    node **similar = (node **)malloc(sizeof(node *) * l);
    unsigned long long *origin = (unsigned long long*)malloc(sizeof(unsigned long long) * k);
    char **word = (char **)malloc(sizeof(char *) * k);
    for (int i = 0; i < k; i++)
        word[i] = (char *)malloc(sizeof(char) * (l+1));
    for (int i = 0; i < l; i++)
        similar[i] = (node *)malloc(sizeof(node) * k);

    unsigned long long d = 0x7E - 0x21 + 1;  // d = 94
    unsigned long long q = ULLONG_MAX / d + 1;    // q = 98120979115476339
    unsigned long long h = 1;


    for (int i = 0; i < k; i++){
        magic[i].index = i;
        magic[i].key = 0;
        scanf("%s", word[i]);
        for (int j = 0; j < l; j++) 
            similar[j][i].key = 0;
        for (int j = 0; j < l; j++){
            unsigned long long hash_num = hash(word[i][j]);
            magic[i].key = (d*magic[i].key % q + hash_num) % q;
            similar[j][i].index = i;       
        }
        origin[i] = magic[i].key;
    }

    for (int j = l-1; j >= 0; j--){
        for (int i = 0; i < k; i++){
            similar[j][i].key = magic[i].key;
            similar[j][i].key += (q - (hash(word[i][j])*h % q));
            similar[j][i].key %= q;
        }
        h *= d;
        h %= q;
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
        unsigned long long ans = 0;
        unsigned long long ct = 1;

        // count # similar pairs
        for (int j = 0; j < l; j++){
            ct = 1;
            for (int i = 0; i < k; i++){
                if (i == k-1)
                    ans += comb2(ct);
                else if(similar[j][i].key == similar[j][i+1].key)
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
            if (i == k-1)
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
            printf("Yes\n%llu", ans);
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