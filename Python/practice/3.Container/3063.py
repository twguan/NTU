n = []
while(1):
    temp = int(input())
    if (temp == -1):
        break
    n.append(temp)
n.sort()
print(n)
n.insert(3, 10)
print(n)
ct = 0
for i in range(len(n)):
    if (n[i] == 10):
        ct += 1
print(ct)
n.sort()
n.reverse()
print(n)