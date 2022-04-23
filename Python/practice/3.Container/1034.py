n = []
for i in range(5):
    n.append(int(input()))
for i in range(5):
    print(n[i], end='\t')
    for j in range(n[i]):
        print("*", end='')
    print()