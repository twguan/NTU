go = 1
last = ''
with open('storeXX.txt') as c:
    lines = c.readlines()
    if last == lines:
        go = 0
        print('yes')
    last = lines
if go:
    print('no')