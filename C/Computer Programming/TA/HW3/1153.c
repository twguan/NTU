#include <stdio.h>
void fill_array(int *ptr[], int n){
	int dist[n], order[n];
	order[n-1] = n-1; order[0] = 0;
	int i, j;
	for (i = 0; i < n; ++i){
		dist[i] = ptr[i] - ptr[0];
		*ptr[i] = i;
		order[i] = i;
	}
	for (i = 0; i < n; ++i){
		int min = dist[i];
		for (j = i; j < n; ++j){
			if (dist[j] < min){
				min = dist[j];
				int swap = dist[j];
				dist[j] = dist[i];
				dist[i] = swap;
				swap = order[j];
				order[j] = order[i];
				order[i] = swap;
			}
		}
	}
	for (i = 0; i < n-1; ++i){
		dist[i] = dist[i+1] - dist[i] - 1;
	}
	for (i = 0; i < n-1; ++i){
		for (j = 1; j <= dist[i]; ++j){
			*(ptr[order[i]] + j) = order[i] + order[i+1];
		}
	}
}