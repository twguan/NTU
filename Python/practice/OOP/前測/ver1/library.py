class Book():
    def __init__(self, name, tags, number):
        self.name = name
        self.tags = tags
        self.number = number
    def print(self):
        print('{name}: {number}'.format(name=self.name, number=self.number))

class Library():
    def __init__(self):
        self.Books = []
        self.tag2books = {}
        self.name2book = {}

    def addBook(self, book_name, tags, number):
        if book_name in self.name2book:
            self.name2book[book_name].number += number
        else:
            book = Book(book_name, tags, number)
            self.Books.append(book)
            for tag in tags:
                if tag not in self.tag2books:
                    self.tag2books[tag] = []
                self.tag2books[tag].append(book)
            self.name2book[book_name] = book
    
    def findBook(self, book_name, tag):
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
