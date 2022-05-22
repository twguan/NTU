from Pokemon import Pokemon

class Eve(Pokemon):
    def Tackle(self, tar):
        if self.__HpCur == 0:
            print(self.__Name, 'is unable to attack.')
        elif tar.__HpCur == 0:
            print(self.__Name, ' cannot attack fainted target ', tar.__Name, '.', sep='')
        else:
            print(self.__Name, 'uses move Tackle to Attack', tar.__Name, int(self.__Lv * 2.5), 'Points.')
            tar.Defence(int(self.__Lv * 2.5))
    def Swift(self, tar):
        if self.__HpCur == 0:
            print(self.__Name, 'is unable to attack.')
        elif tar.__HpCur == 0:
            print(self.__Name, ' cannot attack fainted target ', tar.__Name, '.', sep='')
        else:
            print(self.__Name, 'uses move Swift to Attack', tar.__Name, int(self.__Lv * 5.5), 'Points.')
            tar.Defence(int(self.__Lv * 5.5))