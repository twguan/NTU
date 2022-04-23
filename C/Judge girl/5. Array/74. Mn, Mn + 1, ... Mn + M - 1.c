#include <stdio.h>

int main(){
	int n,N;
	scanf("%d", &n);
	int num[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	scanf("%d", &N);
	int ans[N];
	for (int i = 0; i < N; ++i){
		ans[i] = 0;
	}
	for (int i = 0; i < n; ++i){
		ans[num[i] % N]++;
	}
	for (int i = 0; i < N; ++i){
		printf("%d\n", ans[i]);
	}
	return 0;
}
