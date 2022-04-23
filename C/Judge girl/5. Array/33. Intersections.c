#include <stdio.h>

int main(){
	int n, i, j;
	int city[102][102] = {0};
	scanf("%d", &n);
	for (i = 1; i <= n; ++i){
		for (j = 1; j <= n; ++j){
			scanf("%d", &city[i][j]);
		}
	}
	int inter = 0, T = 0, turn = 0, dead = 0;
	for (i = 1; i <= n; ++i){
		for (j = 1; j <= n; ++j){
			if (city[i][j] == 1){
				int sum = city[i-1][j] + city[i][j-1] + city [i][j+1] + city[i+1][j];
				if (sum == 4)
					inter ++;
				else if (sum == 3)
					T++;
				else if (sum == 2 && city[i][j-1] + city[i][j+1] != 2 && city[i-1][j] + city[i+1][j] != 2)
					turn++;
				else if (sum == 1)
					dead++;
			}
		}
	}
	printf("%d\n%d\n%d\n%d", inter, T, turn, dead);
	return 0;
}
