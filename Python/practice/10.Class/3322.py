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
    def __init__(self, name, lv, hp):
        super().__init__(name, lv, hp)
        self.__Moves = {}
        
        self.addMove('QuickAttack',3,'normal')
        self.addMove('Tackle',2.5,'normal')
        self.addMove('Dig',6,'ground')
    
    def addMove(self, mname: str, mpower: float, mtype: str):
        self.__Moves[mname] = Move(mname, mpower, mtype)
    
    def Attack(self, tar:'Pokemon', moveName: str):
        if self.HpCur <= 0:
            print(self.Name, 'is unable to attack.')
            return
        if tar.HpCur <= 0:
            print(self.Name, 'cannot attack fainted target %s.' % tar.Name)
            return
        move = self.__Moves.get(moveName)
        if move == None:
            print('Move name error. Unable to attack.')
            return
        atk = int(self.Lv * move.mpower)
        print(self.Name, 'uses', move.mtype, 'move', move.name, 'to attack', tar.Name, '%d points.' % (atk))
        tar.Defence(atk)
        
        