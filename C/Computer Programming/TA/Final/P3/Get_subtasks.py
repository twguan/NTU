import os

for i in range(10):
    cmd = "Accode.exe < %d.in > %d.out" % (i, i)
    os.system(cmd)
    