#include <stdio.h>
int cross(int x1, int y1, int x2, int y2);
int main(){	
	int a1, a2, b1, b2, c1, c2, d1, d2;
	scanf("%d%d%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2, &d1, &d2);
	if (cross(a1, a2, b1, b2) && cross(b1, b2, c1, c2) && cross(c1, c2, d1, d2) && cross(d1, d2, a1, a2))
		printf("1");
	else
		printf("0");
	return 0;
}
int cross(int x1, int y1, int x2, int y2){
	if (x1 * y2 - x2 * y1 > 0)
		return 1;
	else
		return 0;
}
