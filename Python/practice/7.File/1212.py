fname = input()
f = open(fname, encoding='utf-8')
s1 = f.read()
f.close()
print(s1)