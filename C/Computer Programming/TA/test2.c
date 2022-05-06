#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct phonebook
{
    char name[80];
    char number[80];
    char mail[80];
};
int main()
{
    int n = 0,i;
    char a,filename[80];
    FILE *file1,*file2;
    struct phonebook p[50];
    while(1)
    {
        scanf(" %c", &a);
        if(a=='q')
        {
            break;
        }
        if(a=='i')
        {
            scanf(" %s", p[n].name);
            scanf(" %s", p[n].number);
            scanf(" %s", p[n].mail);
            n += 1;
        }
        else if(a=='l')
        {
            if(n==0)
            {
                printf("No data\n");
            }
            else
            {
                for (i = 0; i < n;i++)
                {
                    printf("#%d\nName: %s\nPhone: %s\nEmail: %s\n",i+1,p[i].name,p[i].number,p[i].mail);
                }
            }
        }
        else if(a=='s')
        {
            scanf(" %s", filename);
            file1 = fopen(filename, "w");
            fprintf(file1, "%d\n", n);
            for (i = 0; i < n;i++)
            {
                fprintf(file1, "%s\t%s\t%s\n", p[i].name, p[i].number, p[i].mail);
            }
            //fflush(file1);
            fclose(file1);
        }
        else if(a=='o')
        {
            scanf(" %s", filename);
            file2 = fopen(filename, "r");
            fscanf(file2, "%d", &n);
            for (i = 0; i < n;i++)
            {
                fscanf(file2, " %s %s %s", p[i].name, p[i].number, p[i].mail);
            }
            fclose(file2);
        }
        else if(a=='c')
        {
            n = 0;
        }
    }
    system("pause");
    return 0;
}