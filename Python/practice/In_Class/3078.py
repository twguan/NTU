def fact(n):
    num = 1
    for i in range(1,n+1):
        num *= i
    return num

def P(n, m):
    if (n < m):
        return 0
    return (fact(n)//fact(n-m))

def C(n, m):
    return (P(n, m)//fact(m))

if __name__ == '__main__':
    a = int(input())
    b = int(input())
    print(P(a,b))
    print(C(a,b))