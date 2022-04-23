d = {'P':'Pikachu', 'M':'Mickey Mouse', 'H':'Hello kitty'}
temp = input()
value = []
while (not temp == '-1'):
    if (temp == '-2'):
        key = list(iter(d))
        key.sort()
        print('keys:', key)
        for i in key:
            value.append(d[i])
        print('values:', value)
    elif (not temp in iter(d)):
        print(temp, 'does not exist. Enter a new one:')
        d[temp] = input()
    else:
        print(d[temp])
    temp = input()
