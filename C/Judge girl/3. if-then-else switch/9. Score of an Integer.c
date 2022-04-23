#include <stdio.h>

int main(){
	
	int a;
	int score = 0;
	scanf("%d", &a);
	if(a % 3 == 0)
		score += 3;
	if(a % 5 == 0)
		score += 5;
	if(a >= 100 && a <= 200)
		score += 50;
	else
		score -= 50;
	if(a <= 0)
		score = -100;
	printf("%d", score);
	
		
	return 0;
}
