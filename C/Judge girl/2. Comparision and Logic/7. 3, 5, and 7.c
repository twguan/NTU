#include <stdio.h>

int main(){
	
	int a;
	scanf("%d", &a);
	if(a % 15 == 0 && a % 7 !=0)
		printf("0");
	else
		printf("1");	
	return 0;
}
