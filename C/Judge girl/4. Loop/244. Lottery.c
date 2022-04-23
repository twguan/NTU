#include <stdio.h>

int main(){
	int sp[3];
	int st[3];
	int i;
	for (i = 0; i < 3; ++i){
		scanf("%d", &sp[i]);
	}
	for (i = 0; i < 3; ++i){
		scanf("%d", &st[i]);
	}
	
	//compare
	int number;
	int count = 0;
	while (scanf("%d", &number) != EOF){
		for (i = 0; i < 3; ++i){
		int first = st[i];
		if (first % 1000 == number % 1000){
			if (first % 10000 == number % 10000){
				if (first % 100000 == number % 100000){
					if (first % 1000000 == number % 1000000){
						if (first % 10000000 == number % 10000000){
							if (first == number)
								count += 200000;
							else
								count += 40000;
						}
						else
							count += 10000;
					}
					else
						count += 4000;
				}
				else
					count += 1000;
			}
			else
				count += 200;
			}
		}
		for (i = 0; i < 3; ++i){
			if (number == sp[i])
				count += 2000000;
		}	
	}
	printf("%d", count);
	return 0;
}
