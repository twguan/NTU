#include <stdio.h>

int main(){
    char name[128];
    int age;
    char gender[128];
    scanf("%s%d%s", &name, &age, &gender);
    printf("Name:%s\nAge:%d\nGender:%s", name, age, gender);
    return 0;
}