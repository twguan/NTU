#include <stdio.h>

int main(){
	int a, b, c, d, e, s, v;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	s = 2*(a*c + b*c + a*b) + 8*d*(a + b + c - 6*e);
	v = a*b*c - 2*d*((a - 2*e)*(c - 2*e) + (a - 2*e)*(b - 2*e) + (b - 2*e)*(c - 2*e));
	
	printf("%d\n", s);
	printf("%d", v);
	return 0;
}
