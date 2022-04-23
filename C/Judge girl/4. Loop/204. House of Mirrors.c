#include <stdio.h>

int main()
{
	int w, d, i, j;
	scanf("%d%d", &w, &d);
	int room[d+2][w+2];
	for (i = 0; i < d+2; ++i){
		for (j = 0; j < w+2; ++j)
			room[i][j] = 0;
	}
	for (i = 0; i < 2*(w+d); ++i){
		if (i < w)
			room[d+1][i+1] = i;
		else if (i < w+d)
			room[d+w-i][w+1] = i;
		else if (i < 2*w+d)
			room[0][w+w+d-i] = i;
		else
			room[i-2*w-d+1][0] = i;
	}
	for (i = 1; i < d+1; ++i){
		for (j = 1; j < w+1; ++j)
			scanf("%d", &room[i][j]);
	} //setting room done
	
	for (i = 0; i < 2*(w+d); ++i){
		int x, y;
		int go = 1;
		if (i < w){
			x = i+1;
			y = d;
			while (!(x == 0 || x == w+1 || y == 0 || y == d+1)){
				if (room[y][x])
					go *= -1;
				if (go == 1)
					y--;
				else
					x++;				
			}
			printf("%d\n", room[y][x]);
		}
		else if (i < w+d){
			x = w;
			y = d+w-i;
			while (!(x == 0 || x == w+1 || y == 0 || y == d+1)){
				if (room[y][x])
					go *= -1;
				if (go == 1)
					x--;
				else
					y++;				
			}
			printf("%d\n", room[y][x]);
		}
		else if (i < 2*w+d){
			x = w+w+d-i;
			y = 1;
			while (!(x == 0 || x == w+1 || y == 0 || y == d+1)){
				if (room[y][x])
					go *= -1;
				if (go == 1)
					y++;
				else
					x--;				
			}
			printf("%d\n", room[y][x]);
		}
		else{
			x = 1;
			y = i-2*w-d+1;
			while (!(x == 0 || x == w+1 || y == 0 || y == d+1)){
				if (room[y][x])
					go *= -1;
				if (go == 1)
					x++;
				else
					y--;				
			}
			printf("%d\n", room[y][x]);
		}
	}
	//printf room
	/*for (i = 0; i < d+2; ++i){
		for (j = 0; j < w+2; ++j)
			printf("%2d ", room[i][j]);
		printf("\n");
	}*/
	return 0;
}
