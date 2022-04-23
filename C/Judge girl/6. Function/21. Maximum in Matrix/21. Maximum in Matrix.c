#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int max(int array[5][5]);

int main() {
	int i, j;
	int array[5][5];
	for (i = 0; i < 5 ; i++)
		for (j = 0; j < 5; j++)
			scanf("%d", &array[i][j]);
	printf("%d\n", max(array));
	return 0;
}

int max(int array[5][5]){
	int i, j;
	int max = array[0][0];
	for (i = 0; i < 5; ++i){
		for (j = 0; j < 5; ++j){
			if (max < array[i][j])
				max = array[i][j];
		}
	}
		return max;
}
