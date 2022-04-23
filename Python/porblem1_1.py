str1 = input()
list1 = str1.split(' ')
map_object = map(int, list1)
list2 = list(map_object)
r = list2[2] ** 2

# x, y, r, n = map(int, input().split())

for i in range(list2[3]):
    str1 = input()
    list1 = str1.split(' ')
    map_object = map(int, list1)
    ptlist = list(map_object)       # a, b = map(int, input().split())
    distance = (ptlist[0] - list2[0]) ** 2 + (ptlist[1] - list2[1]) ** 2
    if (distance > r):
        print("out")
    elif (distance == r):
        print("on")
    else:
        print("in")
    