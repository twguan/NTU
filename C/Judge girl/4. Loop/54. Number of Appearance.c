#include <stdio.h>

int main(){
	int n1, n2, i;
	int ans = 0;
	scanf("%d%d", &n1, &n2);
	for (i = 0; i < 7; ++i){
		if (n1 == n2 % 100)
			ans += 1;
		n2 /= 10;
	}
	printf("%d", ans);

	return 0;
}
