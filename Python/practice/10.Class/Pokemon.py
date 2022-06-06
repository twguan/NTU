from PokemonOG import Pokemon as pkmog
 
class Pokemon(pkmog):
    def Attack(self,tar:'Pokemon',moveName:str=''):
        if self.__HpCur == 0:
            print(self.__Name, 'is unable to attack.')
        elif tar.__HpCur == 0:
            print(self.__Name, ' cannot attack fainted target ', tar.__Name, '.', sep='')
        else:
            print(self.__Name, 'uses move', moveName, 'to attack', tar.__Name, self.__Lv, 'points.')
            tar.Defence(self.__Lv)
            
    def __gt__(self,tar):
        if self.HpMax > tar.HpMax:
            return True
        else:
            return False