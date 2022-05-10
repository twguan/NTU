from collections import defaultdict

class Book():
    def __init__(self, name, tags, num):
        self.name = name
        self.total = num
        self.tags = tags
    
    def __str__(self):
        return '%s: %d' % (self.name, self.total)
    
class Library():
    def __init__(self):
        self.books = dict() # book_name -> book object
        self.tag_to_booknames = defaultdict(list)

    def addBook(self, book_name, tags, book_num):
        if book_name in self.books:
            self.books[book_name].total += book_num
        else:
            book = Book(book_name, tags, book_num)
            self.books[book_name] = book
            for tag in tags:
                self.tag_to_booknames[tag].append(book_name)

    def findBook(self, book_name, tag):
        if book_name != '-':
            if book_name in self.books and (tag == '-' or tag not in self.books[book_name].tags):
                print(self.books[book_name])
            else:
                print('Not Found!')
        elif tag != '-':
            names = sorted(self.tag_to_booknames[tag])
            if len(names) == 0:
                print('Not Found!')
            else:
                books = [self.books[name] for name in names]
                for book in books:
                    print(book)

    def libraryInfo(self):
        for book_name in sorted(self.books.keys()):
            print(self.books[book_name])