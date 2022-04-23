mod = 1000000007

def operation(operator):
    token = operator.pop(0)
    if (token == 'f'):
        return (operation(operator)*4+9) % (mod)
    elif (token == 'g'):
        return (operation(operator)*77 + operation(operator)*77 - 7) % mod
    elif (token == 'h'):
        x = operation(operator)
        y = operation(operator)
        z = operation(operator)
        return (14*x*y - z*z*z*z + 9) % mod
    else:
        return int(token)


n = int(input())
l1 = input().split()
print("%d" % operation(l1), end='')