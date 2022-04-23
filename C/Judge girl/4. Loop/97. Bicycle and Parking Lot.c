#include <stdio.h>

int main(){
	int p, b, i, j;
	scanf("%d", &p);
	int plot[p][4];
	for (i = 0; i < p; ++i){
		plot[i][0] = 0;
		scanf("%d%d%d", &plot[i][1], &plot[i][2], &plot[i][3]);
	}	
	
	scanf("%d", &b);
	int x, y;
	for (i = 0; i < b; ++i){
		scanf("%d%d", &x, &y);
		int dis[p][2];
		for (j = 0; j < p; ++j){
			dis[j][1] = (x - plot[j][1])*(x - plot[j][1]) + (y - plot[j][2])*(y - plot[j][2]);
			dis[j][0] = j;
		}
		//sort the dis array
		int min, k, no;
		for (j = 0; j < p; ++j){
			min = dis[j][1];
		 	for (k = j + 1; k < p; ++k){
		 		if (min > dis[k][1]){
		 			min = dis[k][1];
		 			int temp;
		 			temp = dis[j][0];
		 			dis[j][0] = dis[k][0];
		 			dis[k][0] = temp;
		 			temp = dis[j][1];
		 			dis[j][1] = dis[k][1];
		 			dis[k][1] = temp;
				 }
				 if (min == dis[k][1]){
				 	int a = dis[j][0];
				 	int b = dis[k][0];
				 	if (plot[a][1] > plot[b][1]){
				 		min = dis[k][1];
		 				int temp;
		 				temp = dis[j][0];
		 				dis[j][0] = dis[k][0];
		 				dis[k][0] = temp;
			 			temp = dis[j][1];
			 			dis[j][1] = dis[k][1];
			 			dis[k][1] = temp;
					 }
				 	else if (plot[a][1] == plot[b][1]){
				 		if (plot[a][2] > plot[b][2]){
				 			min = dis[k][1];
		 					int temp;
		 					temp = dis[j][0];
		 					dis[j][0] = dis[k][0];
		 					dis[k][0] = temp;
		 					temp = dis[j][1];
		 					dis[j][1] = dis[k][1];
		 					dis[k][1] = temp;
						 }
					 }
				 }				 
				 
		 	}
		}
		for (j = 0; j < p; ++j){
			no = dis[j][0];
			if (plot[no][0] < plot[no][3]){
				plot[no][0] += 1;
				break;
			}
		}
		
		
	}
	 
	for (i = 0; i < p; ++i){
		printf("%d\n", plot[i][0]);
	}
	return 0;
}
