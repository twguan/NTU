#include <stdio.h>

int main(){
	
	int h, w, d, a, v;
	scanf("%d%d%d", &h, &w, &d);
	a = 2*(h*w + h*d + w*d);
	v = h*w*d;
	printf("%d\n%d", a, v);
	
	return 0;
}
