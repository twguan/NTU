class Pokemon:
    def __init__(self, name, lv, hp):
        if name == '':
            print('Name can''t be empty.')
            self.Name = 'No Name'
        else:
            self.Name = name
        if lv < 1:
            print('Lv setting error.')
            self.Lv = 1
        else:
            self.Lv = lv
        if hp < 1:
            print('Hp setting error.')
            self.HpCur = 1
            self.HpMax = 1
        else: 
            self.HpMax = hp
            self.HpCur = hp
            
    def ShowInfo(self):
        print('Name:', self.Name)
        print('Lv: %d' % self.Lv)
        print('HP: %d/%d' % (self.HpCur, self.HpMax))
        print()       
        
    def Attack(self, tar):
        if self.HpCur == 0:
            print(self.Name, 'is unable to attack.')
        elif tar.HpCur == 0:
            print(self.Name, ' cannot attack fainted target ', tar.Name, '.', sep='')
        else:
            print(self.Name, 'Attack', tar.Name, self.Lv, 'Points.')
            tar.Defence(self.Lv)
    def Defence(self, atkp):
        if self.HpCur <= atkp:
            print(self.Name, 'is fainted.')
            self.HpCur = 0
        else:
            self.HpCur -= atkp
    def Cure(self):
        print(self.Name ,'has restore health.')
        self.HpCur = self.HpMax