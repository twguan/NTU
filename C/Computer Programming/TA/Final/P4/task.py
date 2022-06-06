import random
import string

f = open('store09.txt', 'w')
f_list = open('list09.txt', 'w')

book = []
# for i in range(10):
#     a = ''
#     a.join(random.choice(string.ascii_letters))
#     l.append(a)
num = 10000
print(num, file=f)
for x in range(num):
  book.append(''.join(random.choice(string.ascii_letters) for _ in range(random.randint(6,8))))
book.sort()
for i in range(len(book)):
  print(book[i], random.randint(1,500), file=f)

l = []

for i in range(150):
  l.append(book[random.randint(1, num-1)])
# l.sort()
for i in l:
  print(i, file=f_list)

f.close()
f_list.close()