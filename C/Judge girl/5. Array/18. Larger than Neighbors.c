#include <stdio.h>

int main(){
	int nrow, ncol, i , j;
	scanf("%d%d", &nrow, &ncol);
	int a[nrow][ncol];
	for(i = 0; i < nrow; ++i){
		for(j = 0; j < ncol; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	int maxa[10000] = {0};
	int count = 0;
	//max
	for(i = 0; i < nrow; ++i){
		for(j = 0; j < ncol; ++j){
			int u = 0;
			int d = 0;
			int l = 0;
			int r = 0;
			int c = a[i][j];
			if(i != 0)
				u = a[i-1][j];
			if(i != nrow-1)
				d = a[i+1][j];
			if(j != 0)
				l = a[i][j-1];
			if(j != ncol-1)
				r = a[i][j+1];
			if( c > u && c > d && c > l && c > r){
				maxa[count] = c;
				count += 1;
			}
		}
	}
	for (i = 0; i < count-1; ++i){
		printf("%d\n", maxa[i]);
	}
	printf("%d", maxa[count-1]);
	
	return 0;
}
