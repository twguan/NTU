d = {'P':'Pikachu', 'M':'Mickey Mouse', 'H':'Hello kitty'}
temp = input()
while (not temp == '-1'):
    if (not temp in iter(d)):
        print(temp, 'does not exist. Enter a new one:')
        d[temp] = input()
    else:
        print(d[temp])
    temp = input()