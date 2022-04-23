head, foot = map(int, input().split())
if(head < 0 or foot < 0 or foot % 2 or foot/head < 2):
    print("NO")
else:
    print("YES")
    print(2*head-foot//2, foot//2-head)