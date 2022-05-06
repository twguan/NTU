class Pokemon:
    
    def ShowInfo(self):
        print('Name:', self.Name)
        print('Lv: %d' % self.Lv)
        print('HP: %d/%d' % (self.HpCur, self.HpMax))
        print()