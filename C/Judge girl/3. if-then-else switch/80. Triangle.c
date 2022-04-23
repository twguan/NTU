#include <stdio.h>


int main(){
	int n, i, j;
	scanf("%d", &n);
	int ay[n][6];
	for (i = 0; i < n; ++i){
		for (j = 0; j < 6; ++j)
			scanf("%d", &ay[i][j]);
	}
	
	// 2dim for square of length,
	double l[n][3];
	for (i = 0; i < n; ++i){
		l[i][0] = (ay[i][2]-ay[i][0])*(ay[i][2]-ay[i][0]) + (ay[i][3]-ay[i][1])*(ay[i][3]-ay[i][1]);
		l[i][1] = (ay[i][4]-ay[i][2])*(ay[i][4]-ay[i][2]) + (ay[i][5]-ay[i][3])*(ay[i][5]-ay[i][3]);
		l[i][2] = (ay[i][4]-ay[i][0])*(ay[i][4]-ay[i][0]) + (ay[i][5]-ay[i][1])*(ay[i][5]-ay[i][1]);
	}

	//array sorting
	
	for (i = 0; i < n; ++i){
		//find max
		double max = l[i][0];
		int index = 0;
		for (j = 1; j < 3; ++j){
			if (max < l[i][j]){
				max = l[i][j];
				index = j;
			}
		}
		//switch to 1
		double temp = l[i][0];
		l[i][0] = l[i][index];
		l[i][index] = temp;
		// 2&3
		if (l[i][1]<l[i][2]){
		double temp = l[i][1];
		l[i][1] = l[i][2];
		l[i][2] = temp;
		}
		
		//type of triangle
		
		if (l[i][0] == l[i][1] || l[i][1] == l[i][2])
			printf("isosceles\n");
		else if (l[i][0] == (l[i][1]+l[i][2]))
			printf("right\n");
		else if (l[i][0] > (l[i][1]+l[i][2]))
			printf("obtuse\n");
		else
			printf("acute\n");
		
	}
	return 0;
}
