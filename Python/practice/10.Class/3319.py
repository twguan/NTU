class Pokemon:
    def __init__(self, name, lv, hp):
        if (not name.isalnum()):
            print('Name setting error.')
            self.__Name = 'No Name'
        else:
            self.__Name = name
        if lv < 1:
            print('Lv setting error.')
            self.__Lv = 1
        else:
            self.__Lv = lv
        if hp < 0:
            print('HpCur setting error.')
            print('HpMax setting error.')
            self.__HpMax = 1
            self.HpCur = 0
        else: 
            self.__HpMax = hp
            self.__HpCur = hp
            
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
    
    @property
    def Lv(self):
        return self.__Lv
    
    @Lv.setter
    def Lv(self, lv):
        self.__Lv = lv

    @property
    def HpCur(self):
        return self.__HpCur
    
    @HpCur.setter
    def HpCur(self, c):
        if c < 0:
            print('HpCur setting error.')
            self.__HpCur = 0
        else:
            self.__HpCur = c

    @property
    def HpMax(self):
        return self.__HpMax
    
    @HpMax.setter
    def HpMax(self, c):
        if c < 1:
            print('HpMax setting error.')
            self.__HpMax = 1
        else:
            self.__HpMax = c

    @property
    def Name(self):
        return self.__Name