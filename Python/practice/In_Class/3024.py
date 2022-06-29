import time

t1 = eval(input())
print(time.strftime('%Y-%m-%d %H:%M:%S', time.gmtime(t1)))
print(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(t1)))