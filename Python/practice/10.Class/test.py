import Pokemon
import Eve
import Eve2
import PC
 
eveType = {'no':Pokemon.Pokemon,
           'normal':Eve.Eve,
           'water':Eve2.Vaporeon,
           'electric':Eve2.Jolteon,
           'fire':Eve2.Flareon,}
 
pkm_st = []
n = int(input())
for i in range(n):
    name = input().strip()
    lv = int(input())
    hp = int(input())
    ptype = input()
 
    pkm = eveType.get(ptype, Pokemon.Pokemon)(name,lv,hp)
    #pkm.ShowInfo()
    pkm_st.append(pkm)
 
for pkm in pkm_st:
    mv = input()
    pkm_st[0].Attack(pkm,mv)
    pkm.ShowInfo()
 
pcName = input()
pc1 = PC.PokemonHealthCenter(pcName)
pc1 << pkm_st[-1]
pkm_st[-1].ShowInfo()
pc1 << pkm_st
 
#Pokemon.__gt__ = PC.myGt #這個寫法不能繼承
pkm_st.sort()
 
for pkm in pkm_st:
    pkm.ShowInfo()
 
#以下為測試成員繼承關系
if issubclass(Eve2.Vaporeon,Pokemon.Pokemon) == False: print('Class Inheritance Error')
if issubclass(Eve2.Jolteon,Pokemon.Pokemon) == False: print('Class Inheritance Error')
if issubclass(Eve2.Flareon,Pokemon.Pokemon) == False: print('Class Inheritance Error')
if issubclass(Eve2.Vaporeon,Eve.Eve) == False: print('Class Inheritance Error')
if issubclass(Eve2.Jolteon,Eve.Eve) == False: print('Class Inheritance Error')
if issubclass(Eve2.Flareon,Eve.Eve) == False: print('Class Inheritance Error')
 
while pkm_st:
    pkm_st.pop()