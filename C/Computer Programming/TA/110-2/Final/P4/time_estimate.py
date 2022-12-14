
import os
import time

t1 = time.time()
res = os.system('ACcode.exe < 0.in')
t2 = time.time()
print()
print('time: %f s' % (t2-t1))
input('print enter to continue....')
