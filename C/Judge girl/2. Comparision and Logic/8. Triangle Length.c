#include <stdio.h>

int main(){
	
	int s1, s2, s3;
	scanf("%d%d%d", &s1, &s2, &s3);
	if(s1 > s2){
		int tem;
		tem = s1;
		s1 = s2;
		s2 = tem;
	}
	if(s2 > s3){
		int tem;
		tem = s2;
		s2 = s3;
		s3 = tem;
	}
	if(s1 > s2){
		int tem;
		tem = s1;
		s1 = s2;
		s2 = tem;
	}
	if(s1 + s2 > s3)
		printf("1");	
	else
		printf("0");
	
		
	return 0;
}
