lst = []
tmp = int(input())
while (tmp != -1):
    lst.append(tmp)
    tmp = int(input())
lst2 = lst.copy()
lst2.sort()
print(lst2)
print(len(lst))
print(sum(lst))
print("%.2f" % (sum(lst) / len(lst)))
print(max(lst), lst.index(max(lst))+1, sep='@')
print(min(lst), lst.index(min(lst))+1, sep='@')
print(lst)