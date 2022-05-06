#include <stdio.h>
#include <string.h>

int main(){
    char filename[64];
    char line[128];
    char delims[] = ",";
    char course[64];
    char type[4];
    char credits[4];
    char grade[4];
    int required = 0, elective = 0;

    scanf("%s", filename);
    FILE *f = fopen(filename, "r");
    fgets(line, 128, f);
    while (1){
        char *ptr = NULL;
        fgets(line, 128, f);
        if (line[(strlen(line)-1)] == '\r')
            line[(strlen(line)-1)] = '\0';
        if(feof(f))
            break;
        
        ptr = strtok(line, delims);
        strcpy(course, ptr);
        ptr = strtok(NULL, delims);
        strcpy(type, ptr);
        ptr = strtok(NULL, delims);
        strcpy(credits, ptr);
        ptr = strtok(NULL, delims);
        strcpy(grade, ptr);
        if (!strcmp(type, "R") && strcmp(grade, "F\n"))
            required += (int)(credits[0] - '0');
        if (!strcmp(type, "E") && strcmp(grade, "F\n"))
            elective += (int)(credits[0] - '0');
    }
    printf("Required: %d\nElective: %d\n", required, elective);
    if (required < 72 && elective < 28)
        printf("N\nStudent still needs to complete %d required credits & %d elective credits for graduation.", 72-required, 28-elective);
    else if (required < 72)
        printf("N\nStudent still needs to complete %d required credits for graduation.", 72-required);
    else if (elective < 28)
        printf("N\nStudent still needs to complete %d elective credits for graduation.", 28-elective);
    else
        printf("Y");
    return 0;
}