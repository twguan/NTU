#include <stdio.h>

int max(int *iptr[], int n){
	int i, max;
	max = *iptr[0];
	for (i = 1; i < n; i++){
		if (max < *iptr[i])	
			max = *iptr[i];
	}
	return max;
}
