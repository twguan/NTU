#include <stdio.h>

int main(){
	
	int a, pow;
	scanf("%d%d", &a, &pow);
	
	switch(pow){
		case(1):
		break;
		case(2):
			a *= a;
		break;
		case(3):
			a *= a*a;
		break;
		case(4):
			a *= a*a*a;
			break;
		case(5):
			a *= a*a*a*a;
	}
	printf("%d", a);
		
	return 0;
}
