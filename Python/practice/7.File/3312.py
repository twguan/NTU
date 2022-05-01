start = int(input())
end = int(input())
file = open('./strange.txt', encoding='gb18030', errors='ignore')
for i in range(end):
    s1 = file.readline()
    if i < start-1:
        continue
    print(s1, end='')