x1, y1, r1 = map(int, input().split())
x2, y2, r2 = map(int, input().split())
n = int(input())
a1, a2, a3, a4 = 0, 0, 0, 0
for i in range(n):
    a, b = map(int, input().split())
    if ((a-x1)**2 + (b - y1)**2 <= r1**2):
        if((a-x2)**2 + (b - y2)**2 <= r2**2):
            a1 += 1
        else:
            a2 += 1
    elif ((a-x2)**2 + (b - y2)**2 <= r2**2):
            a3 += 1
    else:
        a4 += 1
print(a1, a2, a3, a4, sep='\n')