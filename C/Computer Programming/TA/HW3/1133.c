#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char filename[64];
    char gun[16];
    int gunnum[5] = {0};
    scanf("%s", filename);
    FILE *f = fopen(filename, "r");
    while(!feof(f)){
        fscanf(f, "%s ", &gun);
        for (int i = 0; i < strlen(gun); ++i)
            if(gun[i] == '-'){
                gun[i] = '\0';
                break;
            }
        if(!strcmp(gun, "PISTOL"))
            gunnum[0]++;
        else if(!strcmp(gun, "SMG"))
            gunnum[1]++;
        else if(!strcmp(gun, "SHOTGUN"))
            gunnum[2]++;
        else if(!strcmp(gun, "AR"))
            gunnum[3]++;
        else if(!strcmp(gun, "SNIPER"))
            gunnum[4]++;
    }
    printf("%d", gunnum[0]);
    for (int i = 1; i < 5; ++i)
        printf(" %d", gunnum[i]);
    fclose(f);
}