s_file, rock_file = input().split()
out_file = open('./history.txt', 'w')
index = 0
i = 0
try:
    f = open('./' + s_file + '.txt')
except FileNotFoundError:
    out_file.write('failed:(')
else:
    n = int(f.readline())
    soldier = []
    for line in f.readlines():
        soldier.append([int(i) for i in line.split()])
    f.close()
    f = open('./' + rock_file + '.txt')
    while 1:
        s1 = f.read(4096)
        for i in range(n):
            d, c = soldier[i]
            while (d > 0):
                index += (c-1) * 4
                rock = int(s1[index+1:index+4])
                d -= rock
                out_file.write('%d %d\n' % (n, d))
        if s1 == '':
            print('EOF')
            break
    