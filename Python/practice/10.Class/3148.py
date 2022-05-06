class Pokemon:
    def __init__(self, name, lv, hp):
        self.Name = name
        self.Lv = lv
        self.HpMax = hp
        self.HpCur = hp
    def ShowInfo(self):
        print('Name:', self.Name)
        print('Lv: %d' % self.Lv)
        print('HP: %d/%d' % (self.HpCur, self.HpMax))
        print()       
        
    def Attack(self, tar):
        print(self.Name, 'Attack', tar.Name, self.Lv, 'Points.')
        tar.HpCur -= self.Lv
         
    def Cure(self):
        print(self.Name ,'has restore health.')
        self.HpCur = self.HpMax