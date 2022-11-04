#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void){
int h,i,j,t,k[10][7];
char n[10];
int r=64;
 
gets(n);
t=strlen(n);
int a[t];
for(h=0;h<t;h++){
  a[h]=n[h];
}
//printf("%d",r);
for(j=0;j<5;j++){
    r = 64;
  for(i=7;i>0;i--){	
    k[j][i]=a[j]/r;
    a[j]-=k[j][i]*r;
    r=r/2;
    printf("%d",k[j][i]);
  }
printf(",");}


	// your code goes here
	return 0;
}
