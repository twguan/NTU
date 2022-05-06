from library import Library

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
        print('---Search Result---')
        library.findBook(book_name, tag)
        print('-------------------\n')
    elif instruction == 'libraryInfo':
        print('---Library Info---')
        library.libraryInfo()
        print('------------------\n')
    elif instruction == 'quit':
        print('Have a nice day!')
        break
