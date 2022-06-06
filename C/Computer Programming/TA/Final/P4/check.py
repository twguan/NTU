for i in range(1, 10):
    go = 1
    last = ''
    with open('store0'+str(i)+'.txt') as c:
        lines = c.readlines()
        for book in lines:
            name = book.split(' ')[0]
            if last == name:
                go = 0
                print(i, 'yes')
            last = name
        if go:
            print(i, 'no')