n = int(input())
big = [0, 0, 0]
small = [8000000, 0, 0]
for i in range(n):
    temp = int(input())
    if (temp > big[0]):
        big[0] = temp
        big[1] = i+1
        big[2] = 0
    elif (temp == big[0]):
        big[2] = i+1
    if (temp < small[0]):
        small[0] = temp
        small[1] = i+1
        small[2] = 0
    elif (small[0] == temp):
        small[2] = i+1

print(big[0], big[1], end='')
if (big[2] != 0):
    print("", big[2])
else:
    print()
print(small[0], small[1], end = '')
if (small[2] != 0):
    print('', small[2])