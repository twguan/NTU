from Pokemon import Pokemon
 
class PokemonHealthCenter:
    def __init__(self, name:str):
        self.Name = name
        
    def __lshift__(self, pkm:list):
        if (isinstance(pkm, list)):
            for p in pkm:
                print('Pokemon ', p.Name, ' has restored health at ', self.Name, '.', sep='')
                p.__HpMax = p.HpCur
        else:
            print('Pokemon ', pkm.Name, ' has restored health at ', self.Name, '.', sep='')
            print(pkm.HpCur)