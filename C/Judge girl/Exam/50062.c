#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXN 100
#define MAXL 25

typedef struct {
    char book_title[MAXL], author[MAXL];
}BookAuthor;
 
typedef struct {
    char book_title[MAXL];
    int selling, date;
}BookSelling;

typedef struct {
    char book_title[MAXL], author[MAXL];
    int selling, date;
}BookInfo;

typedef struct {
    int num; // the number of BookInfo
    BookInfo books[MAXN];
}BookInfoList;

BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[]){
    BookInfoList result;
    result.num = 0;

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (!strcmp(sellingArr[i].book_title, authorArr[j].book_title)){
                BookInfo book;
                strcpy(book.book_title, sellingArr[i].book_title);
                strcpy(book.author, authorArr[j].author);
                book.date = sellingArr[i].date;
                book.selling = sellingArr[i].selling;
                result.books[result.num++] = book;
                break;
            }
        }
    }

    for (int i = 0; i < result.num; i++){
        char b[MAXL];
        strcpy(b, result.books[i].book_title);
        int t = result.books[i].date, ptr = i;
        for (int j = i+1; j < result.num; j++){
            if (strcmp(b, result.books[j].book_title) > 0){
                strcpy(b,result.books[j].book_title);
                t = result.books[j].date;
                ptr = j;
            }
            else if (strcmp(b, result.books[j].book_title) == 0){
                if (result.books[j].date < t){
                    strcpy(b,result.books[j].book_title);
                    t = result.books[j].date;
                    ptr = j;
                }
            }
        }
        BookInfo temp = result.books[i];
        result.books[i] = result.books[ptr];
        result.books[ptr] = temp;
    }
    return result;
}

int main(){
    int N, M;
    BookAuthor authorArr[MAXN];
    BookSelling sellingArr[MAXN];
 
    assert(scanf("%d %d", &N, &M) == 2);
    for(int i = 0; i < N; i++)
        assert(scanf("%s %s", authorArr[i].book_title,
                              authorArr[i].author) == 2);
 
    for(int i = 0; i < M; i++)
        assert(scanf("%s %d %d", sellingArr[i].book_title,
                                 &sellingArr[i].selling,
                                 &sellingArr[i].date) == 3);
 
    BookInfoList result = merge(N, M, authorArr, sellingArr);
 
    for(int i = 0; i < result.num; i++)
        printf("%s %s %d %d\n", result.books[i].book_title,
                                result.books[i].author,
                                result.books[i].date, result.books[i].selling);
 
    return 0;
}