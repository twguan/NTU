n, x, y = map(int, input().split())
degree = 20
if (n % 2 == 0):    #even
    n //= 2
    degree += n * x - (n-1) * y
else:   #odd
    n //= 2
    degree += (n + 1) * x - n * y
print(degree)