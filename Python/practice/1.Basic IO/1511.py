n, x, y = map(int, input().split())
if (n % 2):
    print(20 + (n+1)//2*x - n//2*y)
else:
    print(20 + n//2*(x-y) + y)