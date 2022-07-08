#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[200001];
char h[200001];
char t[200001];
char cmd[1024];
char sx[64];
char sy[64];

int main(){
    for (int i = 0; i < 200001; i++){
        h[i] = '\0';
        t[i] = '\0';
        s[i] = '\0';
    }
    scanf("%s", s);
    int len = strlen(s), hlen = 0, tlen = 0, hct = 0, tct = 0;
    while(1){
        scanf("%s", cmd);
        if(!strcmp(cmd, "replace")){
            scanf("%s %s", sx, sy);
            char cx = sx[0], cy = sy[0];
            for (int i = 0; i < hct; i++)
                if (h[i] == cx)
                    h[i] = cy;
            
            for (int i = 0; i < 200001; i++)
                if (s[i] == cx)
                    s[i] = cy;

            for (int i = 0; i < tct; i++)
                if (t[i] == cx)
                    t[i] = cy;
        }

        else if(!strcmp(cmd, "remove")){
            scanf("%s", sx);
            char cx = sx[0];
            for (int i = 0; i < 200001; i++){
                if (h[i] == cx){
                    h[i] = '\0';
                    hlen--;
                }
            }
            for (int i = 0; i < 200001; i++){
                if (s[i] == cx){
                    s[i] = '\0';
                    len--;
                }
            }
            for (int i = 0; i < 200001; i++){
                if (t[i] == cx){
                    t[i] = '\0';
                    tlen--;
                }
            }
        }

        else if(!strcmp(cmd, "addhead")){
            scanf("%s", sx);
            char cx = sx[0];
            h[hct++] = cx;
            hlen++;
        }
        else if(!strcmp(cmd, "addtail")){
            scanf("%s", sx);
            char cx = sx[0];
            t[tct++] = cx;
            tlen++;
        }
        else if(!strcmp(cmd, "end"))
            break;
        else{
            printf("invalid command %s", cmd);
            return 0;
        }
    }

    int ct = 0, ptr = 100000;
    while (ct < hlen){
        if(h[ptr] != '\0'){
            printf("%c", h[ptr]);
            ct++;
        }
        ptr--;
    }
    ct = 0; ptr = 0;
    while (ct < len){
        if(s[ptr] != '\0'){
            printf("%c", s[ptr]);
            ct++;
        }
        ptr++;
    }
    ct = 0; ptr = 0;
    while (ct < tlen){
        if(t[ptr] != '\0'){
            printf("%c", t[ptr]);
            ct++;
        }
        ptr++;
    }
    return 0;
}