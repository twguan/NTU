#include <stdio.h>

int main(){
	int ay[100];
	int n, i, j, k, l;
	int start;
	int len = 0;
	int count = 0;
	while (scanf("%d", &n) != EOF){
		ay[count] = n;
		count ++;
	}
	//總共有count個數字 
	//find palindrome 
	
	for (i = 1; i < count+1; ++i){
		int go;
		for (j = 0; j < count-i+1; ++j){
			go = 1;
			for (k = 0; k < (i+1)/2; ++k){ //1st palindrome
				if (ay[j+k] != ay[j+i-1-k]){
					go = 0;
					break;
				}
			}
			if (go){
				for (k = count - (j + i); k > 0; --k){
					int o = 1;
					for (l = 0; l < (k+1)/2; ++l){
						if (ay[j+i+l] != ay[j+i+k-1-l]){
							o = 0;
							break;
						}
					}
					if (o){
						if (len <= i + k){
							if (len == i + k){
								if (start > j)
									break;
							}
							len = i + k;
							start = j;
							//printf("i=%d, k=%d, len=%d\n", i, k, i+k);
							break;
						}
					}
				}
			}
			
		}
	}
	//find 2nd palindrome	
	/*for (i = count - (start + len); i > 0; --i){ //length
		int go = 1;
		for (j = 0; j < (i+1)/2; ++j){
			if (ay[start+len+j] != ay[start+len+i-1-j]){
				go = 0;
				break;
			}
		}
		if (go)
			len += i;
			break;
	}*/
	for (i = start; i < start+len; ++i){
		if (i == start+len-1)
			printf("%d", ay[i]);
		else
			printf("%d ", ay[i]);
	}
	return 0;
}
