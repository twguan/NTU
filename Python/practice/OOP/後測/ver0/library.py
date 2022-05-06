from collections import defaultdict

class Book():
    def __init__(self, name, tags, num):
        self.name = name
        self.total = num
        self.available = num
        self.tags = tags
    
    def __str__(self):
        return '%s: %d/%d' % (self.name, self.available, self.total)
    
class Member():
    def __init__(self, name, identity):
        self.name = name
        self.identity = identity
        if identity == 'student':
            self.max_borrowed = 7
        elif identity == 'teacher':
            self.max_borrowed = 5
        else:
            self.max_borrowed = 3
        self.borrowed = []
    
    def canBorrow(self):
        return len(self.borrowed) < self.max_borrowed
    
    def borrowBook(self, book_name):
        self.borrowed.append(book_name)
        self.borrowed.sort()
    
    def returnBook(self, book_name):
        self.borrowed.remove(book_name)
    
class Library():
    def __init__(self):
        self.books = dict() # book_name -> book object
        self.tag_to_booknames = defaultdict(list)
        self.members = dict()

    def addBook(self, book_name, tags, book_num):
        if book_name in self.books:
            self.books[book_name].total += book_num
            self.books[book_name].available += book_num
        else:
            book = Book(book_name, tags, book_num)
            self.books[book_name] = book
            for tag in tags:
                self.tag_to_booknames[tag].append(book_name)

    def findBook(self, book_name, tag, f):
        if book_name != '-':
            if book_name in self.books:
                if tag != '-' and tag not in self.books[book_name].tags:
                    print('Not Found!', file=f)
                else:
                    print(self.books[book_name], file=f)
        elif tag != '-':
            names = sorted(self.tag_to_booknames[tag])
            if len(names) == 0:
                print('Not Found!', file=f)
            else:
                books = [self.books[name] for name in names]
                for book in books:
                    print(book, file=f)

    def libraryInfo(self, f):
        for book_name in sorted(self.books.keys()):
            print(self.books[book_name], file=f)
    
    def addMember(self, member_name, member_identity, f):
        member = Member(member_name, member_identity)
        self.members[member_name] = member
        print('You can borrow at most %d books.' % member.max_borrowed, file=f)
    
    def borrowBook(self, member_name, book_name, f):
        if member_name not in self.members:
            print('You are not our member!', file=f)
        elif not self.members[member_name].canBorrow():
            print('Sorry! You can not borrow more books!', file=f)
        elif self.books[book_name].available <= 0:
            print('Sorry! No enough books for you!', file=f)
        else:
            self.books[book_name].available -= 1
            self.members[member_name].borrowBook(book_name)
            print(self.members[member_name].borrowed, file=f)
    
    def returnBook(self, member_name, book_name, f):
        if member_name not in self.members:
            print('You are not our member!', file=f)
        elif book_name not in self.members[member_name].borrowed:
            print('This book does not belong here or you did not borrow it!', file=f)
        else:
            self.books[book_name].available += 1
            self.members[member_name].returnBook(book_name)
            print(self.members[member_name].borrowed, file=f)