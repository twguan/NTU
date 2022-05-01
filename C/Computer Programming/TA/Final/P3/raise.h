void raise(int performance[3], int *salary){
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum += performance[i];
    sum /= 3;
    if (sum >= 80)
        *salary += 2000;
    else if (sum >= 70)
        *salary += 1000;
    else if (sum < 60)
        *salary -= 500;
}