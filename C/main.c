#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char ary[] ={0};
	int n =0;
	char A =0;
	char B =0;
	int i=0,total=0;
	while(scanf("%c",&ary[i])&&ary[i]!=B){
	i++;
	n++;
	}
	for(i=0;i<n;i++){
		if(ary[i-1] = ary[i]){
			total += 5;
		}
		else if(ary[i-1] > ary[i]){
			total += 10*(ary[i-1]-ary[i]);
		}
		else if(ary[i] > ary[i-1]){
			total += 6*(ary[i]-ary[i-1]);
		}
	}
	printf("%d",total);
	
	
	return 0;
}
