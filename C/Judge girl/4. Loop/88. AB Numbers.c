#include <stdio.h>

int main(){
	int n1, n2, i, j;
	int a[4], b[4];
	scanf("%d%d", &n1, &n2);
	for (i = 3; i >= 0; --i){
		a[i] = n1 % 10;
		b[i] = n2 % 10;
		n1 /= 10;
		n2 /= 10;		
	}
	int A = 0;
	int B = 0;
	for (i = 0; i < 4; ++i){
		if (b[i] == a[i]){
			A += 1;
		}
		else {
			for (j = 0; j < 4; ++j){
				if (b[i] == a[j])
				B += 1;
			}
		}
	}
	printf("%dA%dB", A, B);
	
	return 0;
}
