num = input()
if (not num.find("7") == -1 or int(num) % 7 == 0):
    print("YES")
else:
    print("NO")