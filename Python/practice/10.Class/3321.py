from PokemonOG import Pokemon

class Move():
    def __init__(self, name:str, mpower:float, mtype:str):
        self.__name = name
        self.__mpower = mpower
        self.__mtype = mtype
    @property
    def name(self):
        return self.__name
    
    @property
    def mpower(self):
        return self.__mpower
    
    @property
    def mtype(self):
        return self.__mtype
    
    
class Eve(Pokemon):
    def Attack(self, tar:'Pokemon', move: Move):
        if self.HpCur <= 0:
            print(self.Name, 'is unable to attack.')
            return
        if tar.HpCur <= 0:
            print(self.Name, 'cannot attack fainted target %s.' % tar.Name)
            return
        atk = int(self.Lv * move.mpower)
        print(self.Name, 'uses', move.mtype, 'move', move.name, 'to attack', tar.Name, '%d points.' % (atk))
        tar.Defence(atk)
        
    def Tackle(self, tar:Pokemon):
        if self.HpCur <= 0:
            print(self.Name, 'is unable to attack.')
            return
        if tar.HpCur <= 0:
            print(self.Name, 'cannot attack fainted target %s.' % tar.Name)
            return
        atk = int(self.Lv * 2.5)
        print(self.Name, 'uses move Tackle to attack', tar.Name, '%d points.' % (atk))
        tar.Defence(atk)
    def Swift(self, tar:Pokemon):
        if self.HpCur <= 0:
            print(self.Name, 'is unable to attack.')
            return
        if tar.HpCur <= 0:
            print(self.Name, 'cannot attack fainted target %s.' % tar.Name)
            return
        atk = int(self.Lv * 5.5)
        print(self.Name, 'uses move Swift to attack', tar.Name, '%d points.' % (atk))
        tar.Defence(atk)