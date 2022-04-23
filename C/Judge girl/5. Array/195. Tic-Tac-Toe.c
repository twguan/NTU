#include <stdio.h>

int main(){
	int n, i, j, x, y, ans;
	int slash1 = 0;
	int slash2 = 0;
	int draw = 1;
	scanf("%d", &n);
	int chess = 1;
	int plate[3][3] = {0};
	
		for (i = 0; i < n; ++i){
			scanf("%d%d", &x, &y);
			if (plate[x][y] != 0 || x > 2|| x < 0 || y > 2 || y < 0)
				continue;
			else {
				plate[x][y] = chess;
				chess = -chess;
			}
		}
		
		for (i = 0; i < 3; ++i){
			ans = 0;
			for (j = 0; j < 3; ++j)
				ans += plate[i][j];
			if (ans == 3){
				printf("Black wins.");
				draw = 0;
				break;
			}
			else if (ans == -3){
				printf("White wins.");
				draw = 0;
				break;
			}
		}
		for (i = 0; i < 3; ++i){
			ans = 0;
			for (j = 0; j < 3; ++j)
				ans += plate[j][i];
			if (ans == 3){
				printf("Black wins.");
				draw = 0;
				break;
			}
			else if (ans == -3){
				printf("White wins.");
				draw = 0;
				break;
			}
		}
		slash1 = plate[0][0] + plate[1][1] + plate[2][2];
		slash2 = plate[0][2] + plate[1][1] + plate[2][0];
		if (draw){
			if (slash1 == 3 || slash2 == 3){
				printf("Black wins.");
				draw = 0;
			}
			else if (slash1 == -3 || slash2 == -3){
				printf("White wins.");
				draw = 0;
			}
		}
		
		if (draw)
			printf("There is a draw.");
	return 0;
}

