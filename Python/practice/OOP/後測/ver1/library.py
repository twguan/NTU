class Book():
    def __init__(self, name, tags, number):
        self.name = name
        self.tags = tags
        self.number = number
        self.available = number
    def print(self):
        print('{name}: {available}/{number}'.format(name=self.name, available=self.available, number=self.number))

class Member():
    def __init__(self, name, identity):
        self.name = name
        self.identity = identity
        self.borrowed = []
        if identity == 'student':
            self.maxborrowed = 7
        elif self.identity == 'teacher':
            self.maxborrowed = 5
        else:
            self.maxborrowed = 3
    def isLimit(self):
        return len(self.borrowed) == self.maxborrowed
    def print(self):
        print('Your can borrow at most {maxborrowed} books.'.format(maxborrowed = self.maxborrowed))

class Library():
    def __init__(self):
        self.Books = []
        self.tag2books = {}
        self.name2book = {}
        self.name2member = {}

    def addBook(self, book_name, tags, number):
        if book_name in self.name2book:
            name2book[book_name].number += number
        else:
            book = Book(book_name, tags, number)
            self.Books.append(book)
            for tag in tags:
                if tag not in self.tag2books:
                    self.tag2books[tag] = []
                self.tag2books[tag].append(book)
            self.name2book[book_name] = book
    
    def findBook(self, book_name=None, tag=None):
        if tag == '-':
            if book_name in self.name2book:
                self.name2book[book_name].print()
                return
        elif book_name == '-':
            if tag in self.tag2books:
                booklist = self.tag2books[tag]
                booklist.sort(key = lambda book: book.name)
                for book in booklist:
                    book.print()
                return
        else:
            if book_name in self.name2book:
                book = self.name2book[book_name]
                if tag in book.tags:
                    book.print()
                    return
        print('Not Found!')
            
    def libraryInfo(self):
        booklist = self.Books
        booklist.sort(key = lambda book: book.name)
        for book in booklist:
            book.print()

    def addMember(self, member_name, identity):
        member = Member(member_name, identity)
        self.name2member[member_name] = member
        member.print()

    def borrowBook(self, member_name, book_name):
        if member_name not in self.name2member:
            print('You are not our member!')
        else:
            if self.name2member[member_name].isLimit():
                print('Sorry! You can not borrow more books!')
            elif self.name2book[book_name].available == 0:
                print('Sorry! No enough books for you!')
            else:
                self.name2member[member_name].borrowed.append(book_name)
                self.name2book[book_name].available -= 1
                self.name2member[member_name].borrowed.sort()
                print(self.name2member[member_name].borrowed)

    def returnBook(self, member_name, book_name):
        if member_name not in self.name2member:
            print('You are not our member!')
        else:
            if book_name not in self.name2member[member_name].borrowed:
                print('This book does not belong here or you did not borrow it!')
            else:
                self.name2member[member_name].borrowed.remove(book_name)
                self.name2book[book_name].available += 1
                self.name2member[member_name].borrowed.sort()
                print(self.name2member[member_name].borrowed)               

