from posixpath import split


a, b, c = map(float, input().split())
PI = 3.1415926
ans = c ** 2 * 3
if (c > b):
    ans += (c - b) ** 2
if (c > a):
    ans += (c - a) ** 2
print("%.6f" % (ans * PI / 4))