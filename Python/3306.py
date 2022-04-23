n = int(input())
d = {}
for i in range(n):
    type = int(input())
    if (type == 1):
        key = input()
        value = list(map(int, input().split()))
        d[key] = value
    elif (type == 2):
        key = input()
        mode = int(input())
        if (not key in d):
            print('bad string -999999 social credit')
        else:
            temp = list(d[key])
            if(mode == 1):
                print(temp)
            elif (mode == 2):
                temp.sort()
                print(temp)
            elif (mode == 3):
                temp.sort()
                temp.reverse()
                print(temp)
            else:
                print('channel -group 1 mode passive,NASA is so hard')