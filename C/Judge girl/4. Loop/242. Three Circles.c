#include <stdio.h>

int main(){
	int i, j, k, l, count;
	int ans = 0;
	int x[3], y[3], r[3];
	int store[1200][3] = {0};
	for (i = 0; i < 3; ++i)
		scanf("%d%d%d", &x[i], &y[i], &r[i]);
	for (i = 0; i < 3; ++i){
		for (j = x[i] - r[i]; j <= x[i] + r[i]; ++j){
			for (k = y[i] - r[i]; k <= y[i] + r[i]; ++k){
				if ((j - x[i])*(j - x[i]) + (k - y[i])*(k - y[i]) <= r[i]*r[i]){
					for (l = 0; l < count + 1; ++l){
						if (store[l][0] == j && store[l][1] == k){
							store[l][2] ++;
							break;
							}
						else if (l == count){
							store[l][0] = j;
							store[l][1] = k;
							store[l][2] = 1;
							count++;
						}
					}
				}
			}
		}
	}
	for (i = 0; i < count; ++i){
		if (store[i][2] == 1 || store[i][2] == 3)
			ans++;
	}
	printf("%d", ans);
	
	return 0;
}

