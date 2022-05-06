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