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

class Moves():
    def __init__(self):
        self.__moves = {}
        
    def AddMove(self, mname: str, mpower: float, mtype: str):
        self.__moves[mname] = Move(mname, mpower, mtype)
        
    def DelMove(self, name:str):
        if (name in self.__moves):
            del self.__moves[name]
        else:
            print('move', name, 'delete error, no this move.')
            
    def GetMove(self, name:str):
        if (name in self.__moves):
            return self.__moves[name]
        else:
            print('move', name, 'get error, no this move.')
            return None
            
    @property
    def moves(self):
        return self.__moves
    
    
class Eve(Pokemon, Moves):
    def __init__(self, name='No Name', lv=1, hp=1):
        super().__init__(name, lv, hp)
        super(Pokemon, self).__init__()
        self.AddMove('QuickAttack',3,'normal')
        self.AddMove('Tackle',2.5,'normal')
        self.AddMove('Dig',6,'ground')
    
    
    def Attack(self, tar:'Pokemon', moveName: str):
        move = self.GetMove(moveName)
        if move == None:
            print('Move name error. Unable to attack.')
            return
        if self.HpCur <= 0:
            print(self.Name, 'is unable to attack.')
            return
        if tar.HpCur <= 0:
            print(self.Name, 'cannot attack fainted target %s.' % tar.Name)
            return
        atk = int(self.Lv * move.mpower)
        print(self.Name, 'uses', move.mtype, 'move', move.name, 'to attack', tar.Name, '%d points.' % (atk))
        tar.Defence(atk)
        
    def ShowInfo(self):
        super().ShowInfo()
        m = []
        for i in self.moves:
            m.append(i)
        m.sort()
        print('Moves:', m)
        print()
        
        