bag = map(int, input().split())
baglist = list(bag)
baglist.sort()
n = len(baglist)
gift = baglist[n-1] + baglist[n-3]
trans = 0
i = 1
while (gift):
    trans += (gift % 7) * i
    gift = gift // 7
    i *= 10
print(trans)