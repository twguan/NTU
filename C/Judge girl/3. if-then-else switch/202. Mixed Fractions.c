#include <stdio.h>

int mcf(int i, int j);
int main(){
	int a, b, c, d, e, f, g, h, i, j, n, u;
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
	switch(d){
		case 0:
			if (a < 0)
				b *= -1;
			if (e < 0)
				f *= -1;
			b += a*c;
			f += e*g;
			i = b*g + c*f;
			j = c*g;
			h = i/j;
			i %= j;
			if (i == 0)
				j = 1;
			if (h < 0)
				i *= -1;
			u = mcf(i, j);
			i /= u;
			j /= u;
			printf("%d\n%d\n%d\n", h, i, j);
			break;
		case 1 :
			if (a < 0)
				b *= -1;
			if (e < 0)
				f *= -1;
			b += a*c;
			f += e*g;
			i = b*g - c*f;
			j = c*g;
			h = i/j;
			i %= j;
			if (i == 0)
				j = 1;
			if (h < 0)
				i *= -1;
			u = mcf(i, j);
			i /= u;
			j /= u; 
			printf("%d\n%d\n%d\n", h, i, j); 
			break;
		case 2 :
			if (a < 0)
				b *= -1;
			if (e < 0)
				f *= -1;
			b += a*c;
			f += e*g;
			i = b*f;
			j = c*g;
			h = i/j;
			i %= j;
			if (i == 0)
				j = 1;
			if (h < 0)
				i *= -1;
			u = mcf(i, j);
			i /= u;
			j /= u;
			printf("%d\n%d\n%d\n", h, i, j);
			break;
		
		case 3 :
			if (a < 0)
				b *= -1;
			if (e < 0)
				f *= -1;
			b += a*c;
			f += e*g;
			i = b*g;
			j = c*f;
			h = i/j;
			i %= j;
			if (i == 0)
				j = 1;
			if (h < 0)
				i *= -1;
			u = mcf(i, j);
			i /= u;
			j /= u;
			printf("%d\n%d\n%d\n", h, i, j);
			break;
	}
	return 0;
}

int mcf(int i, int j){
	int temp;
	while (i != 0){
		temp = j % i;
		j = i;
		i = temp;
	}
	return j;	
} 
