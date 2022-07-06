#include <stdio.h>

int main(){

    int k, input, ans = 0, final = 0;
    int ct = 0, check = 1;
    scanf("%d", &k);

    while (1){
        scanf("%d", &input);
        if (!input)
            break;
        
        if (input > 0){
            if (check == 1 || check == -1){
                ct++;
                if (ct == k)
                    check = -1;
                else if (ct > k){
                    ct = k;
                    ans = 0;
                }
            }
            else if (check == 2){
                ct++;
                if (ct == k){
                    ans += 2*k;
                    if (ans >= final)
                        final = ans;
                    check = -1;
                    ct = k;
                }
            }

        }
        else{
            if (check == -1){
                ct++;
                if (ct == 2*k){
                    check = 2;
                    ct = 0;
                }
            }
            else{
                ct = 0;
                check = 1;
                ans = 0;
            }
        }
    }
    if (final)
        final += k;
    printf("%d", final);
    return 0;
}