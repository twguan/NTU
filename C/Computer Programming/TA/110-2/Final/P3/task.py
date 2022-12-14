import random

for i in range(10):
    a = '.in'
    a = str(i) + a
    f = open(a, "w")
    print(random.randint(10, 30)*1000, file=f)
    print(random.randint(50, 80), random.randint(30, 90), random.randint(60, 100), end='', file=f)
    f.close()