#include <stdio.h>
#include <stdlib.h>

int hasEOF = 0;
char s[128];
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

void printnum(unsigned long long int n){
    int num[8];
    unsigned long long int b = 255;
    for (int i = 0; i < 8; i++){
        unsigned long long int c = 0;
        num[i] = (n & b);
        n = n >> 8;
    }
    for (int i = 7; i >= 0; i--)
        printf("%d ", num[i]);
}

int main(){
    unsigned long long int bookshelf = 0;
    int book[256];
    for (int i = 0; i < 256; i++)
        book[i] = 0;
    
    int x;
    while (ReadInt(&x)) {
        if (book[x] == 0){
            book[x] = 1;
            bookshelf = bookshelf << 8;
            bookshelf += x;
        }
        else {
            unsigned long long int b = x;
            unsigned long long int c = 255;
            unsigned long long int d = 0;
            while ((bookshelf & c) != b){
                d += bookshelf & c;
                bookshelf &= ~c;
                c = c << 8;
                b = b << 8;
            }
            d = d << 8;
            bookshelf &= ~c;
            bookshelf += d + x;
        }
    }   
    // output your answer
        printnum(bookshelf);
    return 0;
}