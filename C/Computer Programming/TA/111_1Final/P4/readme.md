# PK大戰
## 題目敘述
足球的比賽時間分為90分鐘的正規時間和30分鐘的延長賽(不包含傷停補時)。當延長賽結束時若是兩隊依然沒有分出高下，就會用PK戰來決一勝負。PK戰的規則為：兩隊各自派出5名球員，前5輪進球較多的一方為勝，如果還是無法分出勝負，便進入驟死賽階段，當一方射進而另一方射失，則射進的球隊便獲得勝利。本題請撰寫一程式來模擬PK戰的情況(不考慮驟死賽)，流程請參照下列敘述。

1. 選人階段

    讀入兩隊球員的名字和資訊後，在**排除守門員後**依照球員的能力值**由高至低**分別為兩隊選出5位球員當作PK戰的人選和順序。

    守門員各隊只會有一位，但並不一定在第一行輸入。
2. PK階段

    由A隊伍先攻，B隊伍的守門員防守，之後攻守互換，此過程稱為一輪。

    在第 $i$ 輪得分的判斷條件如下(每球1分)：
    * 當第 $i$ 位球員的進攻方向和守門員的防守方向相同時，比較兩者的能力值。若球員的能力值 $\leq$ 守門員，則表示防守成功，請印出`[球員姓名] Get Blocked\n`，反之印出`[球員姓名] Goal!\n`

    * 當進攻方向和防守方向不同時，若球員的能力值 $<70$，代表球員自己失誤將球踢飛，請印出`[球員姓名] Miss!\n`，反之印出`[球員姓名] Goal!\n`

    在一輪結束後，請印出`After [i] round, the score is [A隊得分]:[B隊得分]\n\n`

    **特殊情況**

    * 在第1輪和第5輪中，進攻球員會感到壓力龐大，因此僅能發揮90%的能力值。

3. PK結束

    PK戰的結束方式有以下2種

    *  提前結束

        當有隊伍確定獲勝後，PK階段就會立即結束！請印出``

        範例 1： 假設目前在第3輪、B隊進攻的階段，兩隊比數為A 3:0 B。當B隊的第3人沒有得分，代表就算後兩球B隊都有踢進也無法取得勝利。PK階段便會由A隊伍以 3:0 獲勝。

        範例 2: 假設目前在第4輪、A隊進攻的階段，兩隊比數為A 3:1 B。當A隊的第4人得分。PK階段便會由A隊伍以 4:1 獲勝。

        **注意**  
        若提早結束比賽的時間點為A隊踢完後，不需印出`After [i] round, the score is [A隊得分]:[B隊得分]\n\n`。但若是B隊踢完後才提前結束，需要列印每輪結束後的比分資訊。

    *  5輪都踢完
        當5輪都踢完後，請依最後比分的結果印出`[獲勝隊名] [A隊分數]:[B對分數] win!\n`。若兩隊同分，則印出`Draw [A隊分數]:[B對分數]\n`

## Input format

首先，會有一字串`S1`輸入，代表A隊伍的名字，接著會有11行的輸入，每行的格式為：

`球員姓名`、`守備位置`、`能力值` 以及5個整數 $N_i$ 代表球員在第 $i$ 次點球時想攻擊/防守的位置 `攻擊/守備 方向`。所有資訊皆用一空白隔開。各資訊詳細格式如下

* `球員姓名 S` (字串) : 代表該球員姓名，同一隊保證不會有相同明子的球員，且球員名字小於64字元
* `守備位置 p` (int) : 僅會有`0`或`1`出現，0表示該球員為守門員，1則為其他球員
* `能力值 a` (double) : $0 \leq a \leq 100$ ，表示該球員的能力值。保證同一隊的球員不會有能力值相同的情況。
* `攻擊/守備 方向 d` (int) : 共有5個為`0`、`1`或`2`的數字，其中 $d_i$ 表示該球員在第 $i$ 輪點球中會 攻擊/防守 的方向。0 表示左邊、1表示右邊、2表示中間。

接著輸入會重複以上所有步驟一次，當作B隊伍的資訊。

## Output format

根據上述情形輸出

## Sample input 1
```
ATeam
AAA 0 60 0 0 0 0 0
BBB 1 100 0 0 0 0 0
CCC 1 90 0 0 0 0 0
DDD 1 80 0 0 0 0 0
EEE 1 70 0 0 0 0 0
FFF 1 60 0 0 0 0 0
GGG 1 50 0 0 0 0 0
HHH 1 40 0 0 0 0 0
III 1 30 0 0 0 0 0
JJJ 1 20 0 0 0 0 0
KKK 1 10 0 0 0 0 0
BTeam
aaa 0 63 0 0 0 0 0
bb 1 100 0 0 0 0 0
ccc 1 90 0 0 0 0 0
ddd 1 80 0 0 0 0 0
eee 1 70 0 0 0 0 0
fff 1 60 1 1 1 1 1
ggg 1 55 0 0 0 0 0
hhh 1 46 0 0 0 0 0
iii 1 37 0 0 0 0 0
jjj 1 31 0 0 0 0 0
kkk 1 27 0 0 0 0 0
```

## Sample output 1
```
BBB Goal!
bb Goal!
After 1 round, the score is 1:1

CCC Goal!
ccc Goal!
After 2 round, the score is 2:2

DDD Goal!
ddd Goal!
After 3 round, the score is 3:3

EEE Goal!
eee Goal!
After 4 round, the score is 4:4

FFF Get Blocked!
fff Miss!
After 5 round, the score is 4:4

Draw 4:4

```

## Samle input 2
```
Argentina
Foyth 1 77 0 0 0 1 0
Pezzella 1 78 0 0 0 0 0
Acuna 1 82 1 1 0 1 2
De_Paul 1 85 0 0 0 1 1
Gomez 1 84 1 1 1 0 0
Martinez 0 93 2 0 0 0 1
Paredes 1 88 1 0 1 0 1
Alvarez 1 92 0 0 2 1 2
Messi 1 98 0 0 0 1 2
Di_Maria 1 94 1 2 0 1 2
Dybala 1 89 1 0 0 2 1
Croatia
Barisic 1 94 1 0 0 1 1
Caleta_Car 1 91 1 0 2 1 0
Livakovic 0 93 1 2 1 0 0
Vida 1 79 0 0 0 1 0
Lovren 1 93 1 0 1 0 0
Modric 1 89 0 0 1 2 1
Kovacic 1 92 0 1 0 0 1
Perisic 1 86 1 0 1 0 0
Kramaric 1 88 0 0 1 1 0
Pasalic 1 84 0 2 1 0 0
Vlasic 1 87 0 1 0 2 0
```

## Sample output 2
```
Messi Goal!
Barisic Goal!
After 1 round, the score is 1:1

Di_Maria Goal!
Lovren Get Blocked!
After 2 round, the score is 2:1

Alvarez Goal!
Kovacic Get Blocked!
After 3 round, the score is 3:1

Dybala Goal!
Argentina 4:1 win!

```

## Hint
Sample input 2 的球員狀態
```
        goal keeper for A & B
Martinez        93.0 | Livakovic     93.0
defence :  2 0 0 0 1 | 1 2 1 0 0 

          players for A & B
name       ability pos  name       ability pos
Messi         98.0  0 | Barisic       94.0  1
Di_Maria      94.0  2 | Lovren        93.0  0
Alvarez       92.0  2 | Kovacic       92.0  0
Dybala        89.0  2 | Caleta_Car    91.0  1
Paredes       88.0  1 | Modric        89.0  1
```

## Subtasks
* Subtask 0 (30%): 守門員一定在第一位、能力值為由大到小、 $di = 0$、不會提早結束
* Subtask 1 (20%): 守門員一定在第一位、能力值為由大到小、不會提早結束
* Subtask 2 (10%): 不會提早結束
* Subtask 3-6 (40%): 沒有限制