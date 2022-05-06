from library import Library

f = open('3.out', 'w')

library = Library()
while True:
    instruction = input()
    if instruction == 'addBook':
        book_name, tags, book_num = input().split('|')
        tags = tags.split(' ')
        book_num = int(book_num)
        library.addBook(book_name, tags, book_num)
    elif instruction == 'findBook':
        book_name, tag = input().split('|')
        print('---Search Result---', file=f)
        library.findBook(book_name, tag, f)
        print('-------------------\n', file=f)
    elif instruction == 'libraryInfo':
        print('---Library Info---', file=f)
        library.libraryInfo(f)
        print('------------------\n', file=f)
    elif instruction == 'addMember':
        member_name, member_identity = input().split('|')
        print('---Add Member---', file=f)
        library.addMember(member_name, member_identity, f)
        print('----------------\n', file=f)
    elif instruction == 'borrowBook':
        member_name, book_name = input().split('|')
        print('---Borrow Book---', file=f)
        library.borrowBook(member_name, book_name, f)
        print('-----------------\n', file=f)
    elif instruction == 'returnBook':
        member_name, book_name = input().split('|')
        print('---Return Book---', file=f)
        library.returnBook(member_name, book_name, f)
        print('-----------------\n', file=f)
    elif instruction == 'quit':
        print('Have a nice day!', file=f)
        break

f.close()