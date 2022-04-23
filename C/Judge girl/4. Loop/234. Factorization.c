#include <stdio.h>
#include <math.h>
int main(){
	int a, b, c, i, j, k, absc;
	int count = 0;
	scanf("%d%d%d", &a, &b, &c);
	int sol[3];
	int factor[100000] = {0};
	if (c < 0)
		absc = -c;
	else
		absc = c;
	int d, e, f;
	if (b == 0 && c == 0){
		if (a < 0)
			printf("%d 0 0", a);
		else
			printf("0 0 %d", a);
	}	
	else if (c == 0){
		f = -(-a-sqrt(a*a-4*b))/2;
		e = 0;
		d = -(-a+sqrt(a*a-4*b))/2;
		if (d > 0){
			int temp = d;
			d = e;
			e = temp;
		}
		else if (f < 0){
			int temp = f;
			f = e;
			e = temp;
		}
		printf("%d %d %d", d, e, f);
	}

	else {
		for (i = -absc; i < absc + 1; ++i){
		if (i == 0)
			continue;
		if (c % i == 0){
			factor[count] = i;
			count++;
			}
		}

	 	int find = 0;
		for (i = 0; i < count; ++i){
			for (j = 0; j < count; ++j){
				for (k = 0; k < count; ++k){
					d = factor[i];
					e = factor[j];
					f = factor[k];
					if (d*e*f == c && (d*e+d*f+e*f) == b &&(d+e+f)==a){
						printf("%d %d %d", d, e, f);
						find = 1;
						break;
					}				
				}
				if (find)
					break;
			}
			if (find)
				break;
		}
	}
	return 0;
}

