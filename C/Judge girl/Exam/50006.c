#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int eval(int exp[]){
    int stack[1024], ct = 0;
    int pre_lv = 0;
    for (int i = 1; i <= exp[0]; i++){
        if (i % 2)
            stack[ct++] = exp[i];

        else{
            int now_lv;
            if (exp[i] == 1 || exp[i] == 2)
                now_lv = 1;
            else if (exp[i] == 3 || exp[i] == 4)
                now_lv = 2;
            else
                return -2147483646;
            while(ct > 1 && pre_lv >= now_lv){
                int a = stack[ct-3];
                int op = stack[ct-2];
                int b = stack[ct-1];
                ct -= 3;
                if (op == 1)
                    a += b;
                else if (op == 2)
                    a -= b;
                else if (op == 3)
                    a *= b;
                else if (op == 4)
                    if(b)
                        a /= b;
                    else
                        return -2147483647;
                stack[ct++] = a;
                if (ct > 1)
                    if (stack[ct-2] == 1 || stack[ct-2] == 2)
                        pre_lv = 1;
                    else
                        pre_lv = 2;
            }
            stack[ct++] = exp[i];
            pre_lv = now_lv;

        }
    }
    while (ct > 1){
        int a = stack[ct-3];
        int op = stack[ct-2];
        int b = stack[ct-1];
        ct -= 3;
        if (op == 1)
            a += b;
        else if (op == 2)
            a -= b;
        else if (op == 3)
            a *= b;
        else if (op == 4)
            if(b)
                a /= b;
            else
                return -2147483647;
        stack[ct++] = a;
    }
    return stack[0];
}

int main() {
    int exp[1024];
    memset(exp, -1, sizeof(exp));
    scanf("%d", &exp[0]);
    for (int i = 1; i <= exp[0]; i++)
        scanf("%d", &exp[i]);
    int ret = eval(exp);
    printf("%d\n", ret);
    return 0;
}