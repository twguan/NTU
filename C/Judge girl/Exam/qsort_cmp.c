int cmp_int(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int cmp_str(const void *a, const void *b){
    char *sa = (char *)a;
    char *sb = (char *)b;
    return strcmp(sa, sb);
}

typedef struct A{
    int x;
    int y;
}A;

int cmp_struct(const void *a, const void *b){
    return (*(A *)a).x - ((*A *)b).x
}

int A[30];
// Selection sort
int main(){
    for (int i = 0; i < A.len; i++){
        int min = A[i], idx = i;
        for  (int j = i+1; j < A.len; j++){
            if (A[j] < min){
                min = A[j];
                idx = j;
            }
        }
        swap(A[i], A[idx]);
    }

    char str[100];
    char *d = " ,"; // 想切的字
    char *ptr;
    ptr = strtok(str, d);
    while (ptr != NULL){
        printf("%s\n", ptr);
        ptr = strtok(NULL, d);
    }
    
}

