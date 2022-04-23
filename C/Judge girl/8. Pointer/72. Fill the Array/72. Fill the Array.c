#include <stdio.h>
//#include "fill_array.h"
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

int main() {
    //int arr[100] = {};
    //int *ptr[100];
    //int n = 6, m = 0, i;
    //int A[100] = {0, 5, 6, 9, 3, 12};
    int n, n2, m = 0, i;
    scanf("%d%d", &n, &n2);
    int A[n2];
    int arr[n2];
    for (i = 0; i < n2; i++){
    	arr[i] = 0;
	}
    int *ptr[n2];
    for (i = 0; i < n; i++) {
    	scanf("%d", &A[i]);
	}
    for (i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}
