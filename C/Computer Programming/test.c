#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// C:\Users\unsweet\Desktop\csad\0-1.txt

int main()
{
    FILE *ofile, *tfile;

    //開檔
    char one[128], two[128], last_one[128] = "../app/", last_two[128] = "../app/";
    int i = 0, a_1 = 0, b_1 = 0, a[200], b[200];
    scanf("%s", &one);
    scanf("%s", &two);
    //讀檔
    strcat(last_one, one);
    ofile = fopen(last_one, "r");
    while (1)
    {
        fscanf(ofile, "%d", &a[a_1]);

        if (feof(ofile))
            break;
        a_1++;
    }
    fclose(ofile);
    //讀檔
    strcat(last_two, two);
    tfile = fopen(last_two, "r");
    while (1)
    {
        fscanf(tfile, "%d", &b[b_1]);
        // b_1++;
        if (feof(tfile))
            break;
        b_1++;
    }
    fclose(tfile);
	printf("a1 %d, b1 %d\n", a_1, b_1);
    //存入
    int p[100000];
    // p = (int *)malloc(sizeof(int) * (a_1 + b_1));

    for (i = 0; i < a_1; i++)
    {
        p[i] = a[i];
    }
    for (i = 0; i < b_1; i++)
    {
        p[a_1 + i] = b[i];
    }

    // sort
    int cool, temp, j;
    for (i = (a_1 + b_1); i > 1; i--)
    {
        cool = 0;
        for (j = 0; j < i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                cool = 1;
            }
        }
        if (cool == 0)
            break;
    }
    // print
    for (i = 0; i < (a_1 + b_1); i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    return 0;
}