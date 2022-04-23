a = input().strip()
f = 1.0
i = 1
while(a != 'q'):
    a = eval(a)
    if(type(a) == type(1)):     # a%1 = 0 -> int
        i *= a                  # a%1 != 0 -> float
    else:
        f *= a
    a = input()
print("%.2f" % f)
print(i)
if (f > i):
    print("Float > Int")
elif (f == i):
    print("Float = Int")
else:
    print("Float < Int")