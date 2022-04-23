#include <stdio.h>


int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	int n;
	int start;
	scanf("%d", &start);
	while (scanf("%d", &n) != EOF){
		start = start * n / gcd(start, n);
	}
	printf("%d", start);
}

