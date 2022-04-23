#include <stdio.h>

int main(){
	int year, start;
	int leap = 0;
	scanf("%d%d", &year, &start);
	if (year % 4 == 0 && year % 100 != 0)
		leap = 1;
	if (year % 400 ==0)
		leap = 1;
	int num, i;
	scanf("%d", &num);
	int dayay[num];
	int month, day, big, sm, dif;
	for (i = 0; i < num; ++i){
		scanf("%d%d", &month, &day);
		if (month >= 13 || month < 1){
				dayay[i] = -1;
				continue;
			}
		else if (month == 2){
			if (leap){
				if (day > 29 || day < 1){
					dayay[i] = -2;
					continue;
				}
			}
			else {
				if (day > 28 || day < 1){
				dayay[i] = -2;
				continue;
				}
			}
		}
		else if (month <= 7 && month % 2 == 1){
			if (day > 31 || day < 1){
				dayay[i] = -2;
				continue;
			}
		}
		else if (month > 7 && month % 2 == 0){
			if (day > 31 || day < 1){
				dayay[i] = -2;
				continue;
			}
		}
		else{
			if (day > 30 || day < 1){
				dayay[i] = -2;
				continue;
			}
				
		}
		//determine the day ¤Ñ¼Æ¬Û´îmod7 + start 
		if (month > 8){
				big = ((month-1)/2+1);
				sm = month - big - 2;
				dif = big*31+sm*30+28+day-1;
			if (leap){
				dif += 1;
			}
		}
		else if (month == 1){
			dif = day - 1;
		}
		else if (month == 2)
			dif = day + 30;
		else {
				big = (month-2)/2+1;
				sm = month - big - 2;
				if (sm < 0)
					sm = 0;
				dif = big*31+sm*30+28+day-1;
			if (leap){
				dif += 1;
			}
		}
		dayay[i] = dif % 7 + start;
		if (dayay[i] > 6)
			dayay[i] -= 7;
	}
	for ( i = 0; i < num; ++i)
		printf("%d\n", dayay[i]);
	
	
	return 0;
}
