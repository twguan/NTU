void raise(int performance[3], int *salary){
    int sum = 0, go = 1;
    for (int i = 0; i < 3; i++){
        sum += performance[i];
        if (performance[i] < 60)
            go = 0;
    }
    sum /= 3;
    if (sum >= 80 && go)
        *salary += 2000;
    else if (sum >= 70)
        *salary += 1000;
    else if (sum < 60)
        *salary -= 500;
}