void shuffle(int *deck[])
{
	int n = 0, i;
	while(deck[n] != NULL)
		n++;
	for (i = 0; i < (n+1)/2; ++i)
		deck[i*2] -= i;
	for (i = 0; i < n/2; ++i)
		deck[2*i+1] += (n-1)/2-i;
}

void print(int *deck[])
{
	int i = 0;
	while (deck[i] != NULL)
		printf("%d ", *deck[i++]);
}
