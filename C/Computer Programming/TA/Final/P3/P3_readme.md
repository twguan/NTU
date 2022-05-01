# C/C++ Final P3
## 佛心公司的年終回饋
## 題目說明
佛心公司在偉大的CEO晨晨的帶領下，在今年創造了很好的營收，於是有著「力量人」外號的晨晨，決定在年終依據員工們的考績幫他們加薪，讓員工們獲得金錢的「力量」。
考績總共有3次，且都為正整數，範圍落在`0<=考績<=100`。加薪會依據3次考績的平均(無條件捨去)作為標準，詳細標準如下：
* 平均考績>=80：加薪2000元
* 80>平均考績>=70:加薪1000元
* 平均考績<60: 扣薪500元

身為晨晨特助的你，請幫晨晨寫一隻函式來調整員工們的薪水。並將函式分為`raise.c`與`raice.h`上傳。
函式原型如下：
```c=
void raise(int performance[3], int *salary);
```

以下為測試用之`main.c`
```c=
#include <stdio.h>
#include "raise.h"

int main(){
    int performance[3], salary;
    scanf("%d", &salary);
    for (int i = 0; i < 3; i++)
        scanf("%d", &performance[i]);
    raise(performance, &salary);
    printf("%d", salary);
    return 0;
}
```

注意! 調整後的薪水不會低於0，也不會超出`int`的範圍外

## Input Format
總共有2行
第一行為員工的薪水。
第二行為該員工3次的考績，以空白間隔。

## Output Format
僅一行，為該員工調整過後的薪水。

## Input Sample
```
24000
95 90 88
```

## Output Sample
```
26000
```

## Input Sample
```
32000
78 81 80
```

## Output Sample
```
33000
```
