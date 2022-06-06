from PokemonOG import Pokemon
from Eve import Eve
 
class Vaporeon(Eve):
    def __init__(self,name:str="No Name",lv:int=1,hp:int=1, mtype:str=''):
        super().__init__(name, lv, hp)
        self.__Type = 'water'
        self.AddMove('WaterGun',3,'water')#水槍
        self.AddMove('WaterPulse',4.5,'water')#水之波動
        self.AddMove('HydroPump',6,'water')#水炮
        
    def ShowInfo(self):
        print('Type: water')
        super().ShowInfo()
    def __gt__(self,tar):
        if self.HpMax > tar.HpMax:
            return True
        else:
            return False
        
class Jolteon(Eve):
    def __init__(self,name:str="No Name",lv:int=1,hp:int=1, mtype:str=''):
        super().__init__(name, lv, hp)
        self.__Type = 'electric'
        self.AddMove('ThunderShock',3,'electric')#電擊
        self.AddMove('Thunderbolt',4.5,'electric')#十萬伏特
        self.AddMove('Thunder',5.5,'electric')#打雷
        
    def ShowInfo(self):
        print('Type: electric')
        super().ShowInfo()
    def __gt__(self,tar):
        if self.HpMax > tar.HpMax:
            return True
        else:
            return False
        
class Flareon(Eve):
    def __init__(self,name:str="No Name",lv:int=1,hp:int=1, mtype:str=''):
        super().__init__(name, lv, hp)
        self.__Type = 'fire'
        self.AddMove('Ember',3,'fire')#火花
        self.AddMove('FireSpin',4.3,'fire')#火焰旋渦
        self.AddMove('Flamethrower',7,'fire')#噴射火焰
    
    def ShowInfo(self):
        print('Type: fire')
        super().ShowInfo()
    def __gt__(self,tar):
        if self.HpMax > tar.HpMax:
            return True
        else:
            return False