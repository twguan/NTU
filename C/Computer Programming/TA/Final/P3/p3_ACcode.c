#include <stdio.h>
#include "raise.h"

int main(){
    int performance[3], salary;
    scanf("%d", &salary);
    for (int i = 0; i < 3; i++)
        scanf("%d", &performance[i]);
    raise(performance, &salary);
    printf("%d", salary);
    return 0;
}