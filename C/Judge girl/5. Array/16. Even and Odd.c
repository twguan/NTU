#include <stdio.h>

int main(){
	int n, i;
	int co = 0;
	int ce = 0;
	scanf("%d", &n);
	int a[n];
	int c[n];
	for(i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < n; ++i){
		if(a[i] % 2 == 0){
			c[i] = 0;
			ce += 1;
		}
		else{
			c[i] = 1;
			co += 1;
		}
	}
	//print odd sequence
	int count = 0;
	for(i = 0; i < n; ++i){
		if(c[i] == 1){
			printf("%d", a[i]);
			count += 1;
			if(count != co)
				printf(" ");
		}
	}
	printf("\n");
	//print even sequence
	count = 0;
	for(i = 0; i < n; ++i){
		if(c[i] == 0){
			printf("%d", a[i]);
			count += 1;
			if(count != ce)
				printf(" ");
		}
	}
	return 0;
}
