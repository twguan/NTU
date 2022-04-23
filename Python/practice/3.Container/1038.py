n = int(input())
lst = input().split()
for i in range(n-1, 0, -1):
    print(lst[i], end=' ')
print(lst[0])