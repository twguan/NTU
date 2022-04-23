#include <stdio.h>

int main(){
	int nrow, ncol, i, j;
	scanf("%d%d", &nrow, &ncol);
	int a[nrow][ncol];
	for(i = 0; i < nrow; ++i){
		for(j = 0; j < ncol; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	for(j = 0; j < ncol; ++j){
		int ave = 0;
		for(i = 0; i < nrow; ++i){
			ave += a[i][j];
		}
		ave /= nrow;
		printf("%d\n", ave);
	}
	return 0;
}
