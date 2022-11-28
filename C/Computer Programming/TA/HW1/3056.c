#include<stdio.h>
 
int main(){
    int n,m,yes=0,temp=0;
    scanf("%d %d",&n,&m);
    for(int i=n;i<=m;i++){
        if(i%7==0 && yes == 0){
            printf("%d",i);
            yes = 1;
        }
        else if(i%7==0)
            printf(" & %d",i);
    }
    printf("\n");
    yes = 0;
    for(int i=n;i<=m;i++){
        temp=i;
        while(temp != 0){
            if(temp%10 == 7){
                if(yes == 0){
                    printf("%d",i);
                    yes = 1;
                }
                else if(yes == 1)
                    printf(" & %d",i);
                break;
            }
            temp /= 10;
        }
    }
    return 0;
}