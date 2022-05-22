class Pokemon:
    def __init__(self, name='', lv=0, hp=0):
        if name == '':
            self.__Name = 'No Name'
        elif name == ' ' or name in (',.!@#$'):
            print('Name can''t be empty.')
            self.__Name = 'No Name'
        else:
            self.__Name = name
        if lv < 1:
            print('Lv setting error.')
            self.__Lv = 1
        else:
            self.__Lv = lv
        if hp < 1:
            print('Hp setting error.')
            self.__HpCur = 1
            self.__HpMax = 1
        else: 
            self.__HpMax = hp
            self.__HpCur = hp
            
    def __del__(self):
        print(self.__Name, 'has returned to the nature.')
        
    def ShowInfo(self):
        print('Name:', self.__Name)
        print('Lv: %d' % self.__Lv)
        print('HP: %d/%d' % (self.__HpCur, self.__HpMax))
        print()       
        
    def Attack(self, tar):
        if self.__HpCur == 0:
            print(self.__Name, 'is unable to attack.')
        elif tar.__HpCur == 0:
            print(self.__Name, ' cannot attack fainted target ', tar.__Name, '.', sep='')
        else:
            print(self.__Name, 'Attack', tar.__Name, self.__Lv, 'Points.')
            tar.Defence(self.__Lv)
    def Defence(self, atkp):
        if self.__HpCur <= atkp:
            print(self.__Name, 'is fainted.')
            self.__HpCur = 0
        else:
            self.__HpCur -= atkp
    def Cure(self):
        print(self.__Name ,'has restore health.')
        self.__HpCur = self.__HpMax