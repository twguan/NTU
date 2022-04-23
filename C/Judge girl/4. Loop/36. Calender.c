#include <stdio.h>

int main(){
	int year, month, start, i;
	int leap = 0;
	scanf("%d%d%d", &year, &month, &start);
	if (year % 4 == 0 && year % 100 != 0)
		leap = 1;
	if (year % 400 ==0)
		leap = 1;
	int days;
	int countw = 0;
	if (month == 2){
		if (leap)
			days = 29;
		else
			days = 28;
	}
	else if (month > 7){
		if (month % 2 == 0)
			days = 31;
		else
			days = 30;
	}
	else {
		if (month % 2 == 0)
			days = 30;
		else
			days = 31;
	}
	if (13 > month > 1 )
		printf("y");
	if ((13 > month && month > 0 ) && (7 > start && start >= 0)){
		printf(" Su Mo Tu We Th Fr Sa\n");
		printf("=====================\n");
		while (countw != start){
				printf("   ");
				countw++;	
		}
		for (i = 1; i < days + 1; i++){
			if (countw == 7){
					printf("\n");
					countw = 0;
				}
			printf("%3d", i);
			countw++;
		}
		printf("\n");
		printf("=====================\n");
	}
	else {
		printf("invalid\n");
	}
	
	return 0;
}
