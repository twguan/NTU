1],[0,0,1,1,0]]
gg = []
for i in range(8):
    temp = list(map(int, input().split()))
    gg.append(temp)
a = 'A'
str = BD_Construction(gg, a)
print(str)