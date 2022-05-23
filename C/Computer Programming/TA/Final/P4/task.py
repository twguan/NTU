import random
import string

f = open('storeXX.txt', 'w')
f_list = open('listXX.txt', 'w')

l = []
# for i in range(10):
#     a = ''
#     a.join(random.choice(string.ascii_letters))
#     l.append(a)
num = 100000
print(num, file=f)
for x in range(num):
  l.append(''.join(random.choice(string.ascii_letters) for _ in range(random.randint(6,8))))
l.sort()
for i in range(len(l)):
  print(l[i], random.randint(1,500), file=f)

for i in range(200):
  print(l[random.randint(1, num)], file=f_list)

f.close()
f_list.close()