find, txt = input().split()
ct = 0
for i in range(len(txt)-len(find)+1):
    txt2 = txt[i:i+len(find)]
    if (not txt2.find(find) == -1):
        ct += 1
print(ct)