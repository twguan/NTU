#include <stdio.h>
#include <ctype.h>

typedef struct info{
    char name[32];
    char phone[12];
    char email[32];
}Info;

int main(){
    int num = 0;
    Info list[50];
    char order, filename[32];
    scanf("%c", &order);
    while (order != 'q'){
        if (order == 'i'){
            scanf("%s%s%s", list[num].name, list[num].phone, list[num].email);
            num++;
        }
        else if (order == 'l'){
            if(num == 0){
                printf("No data.\n");
            }
            for (int i = 0; i < num; ++i){
                printf("#%d\n", i+1);
                printf("Name: %s\nPhone: %s\nEmail: %s\n", list[i].name, list[i].phone, list[i].email);
            }
        }
        else if (order == 's'){
            scanf("%s", &filename);
            FILE *f = fopen(filename, "w");
            fprintf(f, "%d", num);
            for (int i = 0; i < num; ++i){
                fprintf(f, "\n%s\t%s\t%s", list[i].name, list[i].phone, list[i].email);
            }
            fclose(f);
        }
        else if (order == 'o'){
            scanf("%s", &filename);
            FILE *f = fopen(filename, "r");
            fscanf(f, "%d", &num);
            for (int i = 0; i < num; ++i){
                fscanf(f, "%s%s%s", &list[i].name, &list[i].phone, &list[i].email);
            }
            fclose(f);
        }
        else if (order == 'c'){
            num = 0;
        }
        scanf(" %c", &order);
    }
    return 0;
}