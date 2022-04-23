int evaluate_f(int *iptr[], int n, int *index){
    int i, max = 4 * *iptr[0] - 6 * *(iptr[0]+1);
    for (i = 0; i < n; ++i){ //x = *iptr[i], y = *(iptr[i]+1)
        if (4 * (*iptr[i]) - 6 * (*(iptr[i]+1)) > max){
            max = 4 * *iptr[i] - 6 * *(iptr[i]+1);
            *index = i;
        }
    }
    return max;
}