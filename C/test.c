void processSetMatrix(int ***ptr) {
    // ptr[2] == NULL
    int ***matptr = ptr;
    while (*matptr){
        int **setptr = *matptr;
        while (*setptr){
            int *num = *setptr;
            while (*num){
                printf("%d ", *num);
                num++;
            }
            setptr++;
        }
        matptr++;
    }
}