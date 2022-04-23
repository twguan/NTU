#include <stdio.h>

int main(){
	int s, f, t;
	int ch, ra, cr;
	scanf("%d%d%d", &s, &f, &t);
	cr = s - t;
	f = f - 8*cr;
	s -= cr;
	ra = (f - 2*s)/2;
	ch = s - ra;
	printf("%d\n%d\n%d\n", ch, ra, cr);
	return 0;
}
