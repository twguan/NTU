#include <stdio.h>

int main(){
	int n, i, input;
	int mod0 = 0;
	int mod1 = 0;
	int mod2 = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		scanf("%d", &input);
		if (input % 3 == 0)
			mod0 += 1;
		else if (input %3 == 1)
			mod1 += 1;
		else
			mod2 += 1;
	}
	printf("%d %d %d", mod0, mod1, mod2);
	return 0;
}
