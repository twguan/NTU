class Pokemon:
    def __init__(self,name='No Name',lv=1,hp=1):
        if name==' ':
            print('Name can\'t be empty.')
            name = 'No Name'
        if lv<1:
            print('Lv setting error.')
            lv = 1
        if hp<1:
            print('Hp setting error.')
            hp = 1
        self.__Name = name
        self.__Lv = lv
        self.__HpCur = hp
        self.__HpMax = hp
            
    def __del__(self):
        print(self.__Name, "has returned to the nature.")
        
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