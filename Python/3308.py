def operation(operator):
    token = operator.pop(0)
    if (token == 'f'):
        return (operation(operator)*2-1) % (1e9+7)
    elif (token == 'g'):
        return (operation(operator) + operation(operator) * 2 - 3) % (1e9+7)
    else:
        return int(token)

n = int(input())
l1 = input().split()
print("%d" % operation(l1))