secret = input()
a = input()
b = input()
secret = ''.join(secret.split())
tab = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz'
ct = 0
for i in range(len(a)):
    if(a[i].isupper() or a[i].isdigit()):
        ct += 1
for i in range(len(b)):
    if(b[i].islower() or b[i] in"#$*@"):
        ct += 1
c = a+b
d = ''
for i in range(len(c)):
    if (c[i].isdigit()):
        d += c[i]
ct += int(d)
base = ct % 60
newtab = tab[-base:] + tab[:-base]
transtab = str.maketrans(tab, newtab)
print(secret.translate(transtab), end='')