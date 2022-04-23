# include <stdio.h>
 
int cp(int v1[2], int v2[2]);

//可以使用4邊形對角平方定理check the order 
int main(){
 	int n, i, x1, x2, x3, x4, y1, y2, y3, y4;
 	scanf("%d", &n);
 	for (i = 0; i < n; ++i){
 		scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
 		
 		int v12[2] = {(x2-x1), (y2-y1)};
 		int v23[2] = {(x3-x2), (y3-y2)};
 		int v34[2] = {(x4-x3), (y4-y3)};
 		int v41[2] = {(x1-x4), (y1-y4)};
 		int r1 = cp(v12, v23);
 		int r2 = cp(v23, v34);
 		int r3 = cp(v34, v41);
 		int temp;
 		if (r1 != r2){
 			temp = x3;
 			x3 = x4;
 			x4 = temp;
 			temp = y3;
 			y3 = y4;
 			y4 = temp;
		 }
 		else if (r1 != r3){
 			temp = x2;
 			x2 = x3;
 			x3 = temp;
 			temp = y2;
 			y2 = y3;
 			y3 = temp;
		 }
 		
 		int a = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
 		int b = (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
 		int c = (x4-x3)*(x4-x3)+(y4-y3)*(y4-y3);
 		int d = (x4-x1)*(x4-x1)+(y4-y1)*(y4-y1);
 		int e = (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
 		int f = (x4-x2)*(x4-x2)+(y4-y2)*(y4-y2);
 		if (a == b && a == c && a == d){
 			if (a+b == e && c+d == e && a+d == f && b+c ==f)
 				printf("square\n");
 			else
 				printf("diamond\n");
		 }
 		else {
 			if (a+b == e && c+d == e && a+d == f && b+c ==f)
 				printf("rectangle\n");
 			else
 				printf("other\n");
		 }
 		
 		
	 }
 	return 0;
 }
 
 int cp(int v1[2], int v2[2]){
 	int z = v1[0]*v2[1]-v1[1]*v2[0];
 	if (z > 0)
 		return 1;
 	else
 		return -1;
 }
