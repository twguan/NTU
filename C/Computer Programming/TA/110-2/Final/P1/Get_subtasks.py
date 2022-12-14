import os

for i in range(0, 5, 1):
    cmd = "Accode.exe < %d.in > %d.out" % (i, i)
    os.system(cmd)
    