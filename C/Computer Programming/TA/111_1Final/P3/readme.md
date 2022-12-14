# Chess Game
## 題目敘述
某天喬伊在看完影集"后翼棄兵"後，有了想學西洋棋的念頭，於是去問他一位很會下棋的好朋友卡爾森，希望卡爾森教他西洋棋的基礎下法。西洋棋盤的大小為8 x 8，所有的棋子都需要下在格子內。而棋子共有6種，分別為`國王(king)`、`皇后(queen)`、`主教(bishop)`、`城堡(rook)`、`騎士(knight)`和`小兵(pawn)`。為了不讓喬伊混亂，卡爾森先教他除了`小兵`和`國王`以外的棋子的走法。

1. 皇后

    可以不限步數的直、橫、斜著走
1. 主教

    可以不限步數的斜著走
1. 城堡

    可以不限步數的直或橫著走
1. 騎士

    騎士的走法和中國象棋的"馬"相同，走「日」字，或英文字母大寫的「L」形

可參考：https://blog.udn.com/puzzlez/4342425

在知道這些棋子的移動方式後，卡爾森決定出個考題來看看喬伊是否真的有學會。卡爾森總共會告訴喬伊`N`個指令，而喬伊需要根據指令來回答問題。指令總共有`queen x y`、`rook x y`、`bishop x y`、`knight x y`、`count`、`print`6種。
定義棋盤的座標x為由上到下，y座標為由左至右，且x、 y皆為從0開始之整數。
* `queen x y`

    在棋盤上(x, y)的位置擺上一個皇后的棋子。請用`4`來代表皇后所在的位置，並將這顆棋子可以走到的部分標示為`-1`，其餘的空格為`0`。如果棋子不能擺放，印出`invalid place\n`，不能擺放的條件請參照後面敘述。

    範例： `queen 4 4`後的棋盤狀況為
    ```
     -1  0  0  0 -1  0  0  0
      0 -1  0  0 -1  0  0 -1
      0  0 -1  0 -1  0 -1  0
      0  0  0 -1 -1 -1  0  0
     -1 -1 -1 -1  4 -1 -1 -1
      0  0  0 -1 -1 -1  0  0
      0  0 -1  0 -1  0 -1  0
      0 -1  0  0 -1  0  0 -1
    ```
* `rook x y`

    在棋盤上(x, y)的位置擺上一個城堡的棋子。請用`3`來代表皇后所在的位置，並將這顆棋子可以走到的部分標示為`-1`，其餘的空格為`0`。如果棋子不能擺放，印出`invalid place\n`，不能擺放的條件請參照後面敘述。

    範例： `rook 4 4`後的棋盤狀況為
    ```
      0  0  0  0 -1  0  0  0
      0  0  0  0 -1  0  0  0
      0  0  0  0 -1  0  0  0
      0  0  0  0 -1  0  0  0
     -1 -1 -1 -1  3 -1 -1 -1
      0  0  0  0 -1  0  0  0
      0  0  0  0 -1  0  0  0
      0  0  0  0 -1  0  0  0
    ```
* `bishop x y`

    在棋盤上(x, y)的位置擺上一個主教的棋子。請用`2`來代表皇后所在的位置，並將這顆棋子可以走到的部分標示為`-1`，其餘的空格為`0`。如果棋子不能擺放，印出`invalid place\n`，不能擺放的條件請參照後面敘述。

    範例： `bishop 4 4`後的棋盤狀況為
    ```
     -1  0  0  0  0  0  0  0
      0 -1  0  0  0  0  0 -1
      0  0 -1  0  0  0 -1  0
      0  0  0 -1  0 -1  0  0
      0  0  0  0  2  0  0  0
      0  0  0 -1  0 -1  0  0
      0  0 -1  0  0  0 -1  0
      0 -1  0  0  0  0  0 -1
    ```
* `knight x y`

    在棋盤上(x, y)的位置擺上一個騎士的棋子。請用`1`來代表皇后所在的位置，並將這顆棋子可以走到的部分標示為`-1`，其餘的空格為`0`。如果棋子不能擺放，印出`invalid place\n`，不能擺放的條件請參照後面敘述。

    範例： `knight 4 4`後的棋盤狀況為
    ```
    0  0  0  0  0  0  0  0
    0  0  0  0  0  0  0  0
    0  0  0 -1  0 -1  0  0
    0  0 -1  0  0  0 -1  0
    0  0  0  0  1  0  0  0
    0  0 -1  0  0  0 -1  0
    0  0  0 -1  0 -1  0  0
    0  0  0  0  0  0  0  0
    ```
* `count`

    列出目前在棋盤上分別有多少個棋子。

* `print`

    將目前棋盤上的狀況整個印出來。**已提供在main.c裡，不需要做任何更動或新增函式**

### invalid place情形
1. 該位置上沒有其他棋子

    如果擺放的位置可以被已經存在在棋盤上的任意一個棋子吃掉(某一個棋子可以合法地走到該位置)，那麼該位置就不能擺放棋子。

2. 該位置上已有擺放棋子

    - 皇后可以取代除了皇后以外的其他棋子
    - 若要擺放的棋子不是皇后，則無論位置上的棋子為何，皆不能擺放。

請注意：後擺放的棋子**不會**吃掉已擺放好的棋子。

本題僅需完成`chess.h`和`chess.c`，`chess.c`的格式為
``` language = C
#include <stdio.h>
#include "chess.h"
void place_queen(int board[8][8], int x, int y){
    // TODO
}

void place_rook(int board[8][8], int x, int y){
    // TODO
}

void place_bishop(int board[8][8], int x, int y){
    // TODO
}

void place_knight(int board[8][8], int x, int y){
    // TODO
}

void count_chess(int board[8][8]){
    // TODO
}
```

主程式`main.c`如下：
``` language = C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chess.h"

int main(){
    int n;
    int board[8][8] = {};
    memset(board, 0, sizeof(board));
    scanf("%d", &n);
    int x, y;
    char op[8];
    for (int i = 0; i < n; ++i){
        scanf("%s", op);
        if (!strcmp(op, "queen")){
            scanf("%d%d", &x, &y);
            place_queen(board, x, y);
        }
        else if (!strcmp(op, "rook")){
            scanf("%d%d", &x, &y);
            place_rook(board, x, y);
        }
        else if (!strcmp(op, "bishop")){
            scanf("%d%d", &x, &y);
            place_bishop(board, x, y);
        }
        else if (!strcmp(op, "knight")){
            scanf("%d%d", &x, &y);
            place_knight(board, x, y);
        }
        else if (!strcmp(op, "count")){
            count_chess(board);
        }
        else if (!strcmp(op, "print")){
            for (int i = 0; i < 8; ++i){
                for (int j = 0; j < 8; ++j)
                    printf("%3d", board[i][j]);
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
```

## Input format
第一行為一正整數`N`，接著共有`N`行指令。

### Constraint
$0 < N <= 100$ , $0 <= x, y <= 7$

## Output format
僅 `count`和`print`指令需要輸出，格式如下：

* `count`
    共5行，前4行分別輸出`#棋子種類: 數量`，第5行為一換行符號。

    範例：
    ```
    #queen: [皇后個數]
    #rook: [城堡個數]
    #bishop: [主教個數]
    #knight: [騎士個數]

    ```
* `print` (不須提供)
    共9行，前8行每行有8個數字，每個數字佔3格寬。第9行為一換行符號`\n`。


## Subtasks

- Subtask 0 (10%)

    只有`rook x y`、`count`和`print`指令。
- Subtask 1 (10%)

    只有`rook x y`、`bishop x y`、`count`和`print`指令。    
- Subtask 2 (20%)

    `rook x y`、`bishop x y`、`knight x y`、`count`和`print`指令。
- Subtask 3 (20%)

    皇后只會下在沒有棋子的地方(不會發生需取代棋子的情況)

- Subtask 4-7 (各10%，總共40%)

    無限制

## Input sample 1
```
6
rook 3 3
bishop 4 4
print
bishop 2 6
count
print
```
## Output sample 1
```
 -1  0  0 -1  0  0  0  0
  0 -1  0 -1  0  0  0 -1
  0  0 -1 -1  0  0 -1  0
 -1 -1 -1  3 -1 -1 -1 -1
  0  0  0 -1  2  0  0  0
  0  0  0 -1  0 -1  0  0
  0  0 -1 -1  0  0 -1  0
  0 -1  0 -1  0  0  0 -1

invalid place
#queen: 0
#rook: 1
#bishop: 1
#knight: 0

 -1  0  0 -1  0  0  0  0
  0 -1  0 -1  0  0  0 -1
  0  0 -1 -1  0  0 -1  0
 -1 -1 -1  3 -1 -1 -1 -1
  0  0  0 -1  2  0  0  0
  0  0  0 -1  0 -1  0  0
  0  0 -1 -1  0  0 -1  0
  0 -1  0 -1  0  0  0 -1


```

## Input sample 2
```
5
knight 3 3
print
queen 3 3
print
count
```
## Output sample 2
```
  0  0  0  0  0  0  0  0
  0  0 -1  0 -1  0  0  0
  0 -1  0  0  0 -1  0  0
  0  0  0  1  0  0  0  0
  0 -1  0  0  0 -1  0  0
  0  0 -1  0 -1  0  0  0
  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0

 -1  0  0 -1  0  0 -1  0
  0 -1  0 -1  0 -1  0  0
  0  0 -1 -1 -1  0  0  0
 -1 -1 -1  4 -1 -1 -1 -1
  0  0 -1 -1 -1  0  0  0
  0 -1  0 -1  0 -1  0  0
 -1  0  0 -1  0  0 -1  0
  0  0  0 -1  0  0  0 -1

#queen: 1
#rook: 0
#bishop: 0
#knight: 0


```

## Input sample 3
```
9
knight 4 4
bishop 7 7
count
print
rook 4 4
queen 4 4
queen 7 7
count
print
```
## Output sample 3
```
#queen: 0
#rook: 0
#bishop: 1
#knight: 1

 -1  0  0  0  0  0  0  0
  0 -1  0  0  0  0  0  0
  0  0 -1 -1  0 -1  0  0
  0  0 -1 -1  0  0 -1  0
  0  0  0  0  1  0  0  0
  0  0 -1  0  0 -1 -1  0
  0  0  0 -1  0 -1 -1  0
  0  0  0  0  0  0  0  2

invalid place
#queen: 2
#rook: 0
#bishop: 0
#knight: 0

 -1  0  0  0 -1  0  0 -1
  0 -1  0  0 -1  0  0 -1
  0  0 -1  0 -1  0 -1 -1
  0  0  0 -1 -1 -1  0 -1
 -1 -1 -1 -1  4 -1 -1 -1
  0  0  0 -1 -1 -1  0 -1
  0  0 -1  0 -1  0 -1 -1
 -1 -1 -1 -1 -1 -1 -1  4


```