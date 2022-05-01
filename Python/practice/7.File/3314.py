h, a, name = input().split()
H = int(h)
A = int(a)
write = open('./history.txt', 'w')
try:
    f = open('./' + name + '.txt')
except FileNotFoundError:
    write.write('failed:(')
else:
    line = f.readlines()
    num = int(line[0])
    for i in range(num+1):
        if i == 0:
            continue
        h, a = line[i].split()
        sh = int(h)
        sa = int(a)
        while (sh > 0 and H > 0):
            H -= sa
            if H > 0:
                sh -= A
            write.write('%d %d %d\n' % (i-1, sh, H))
    if (H > 0):
        write.write('failed:(')
    else:
        write.write('success!')
write.close()