import Pokemon
import Eve
 
name = input().strip()
lv = int(input())
hp = int(input())
p1 = Pokemon.Pokemon(name,lv,hp)
p1.ShowInfo()
 
name = input().strip()
lv = int(input())
hp = int(input())
p2 = Eve.Eve(name,lv,hp)
p2.ShowInfo()
 
#Round 1
p1.Attack(p2)
p2.Attack(p1)
#Round 2
p1.Attack(p2)
p2.Tackle(p1)
#Round 3
p1.Attack(p2)
p2.Swift(p1)
 
p1.ShowInfo()
p2.ShowInfo()
 
#以下為測試是否將成員設成private(non-public)
private_tester = Pokemon.Pokemon._Pokemon__pkmCt
 
#以下為測試是否將成員設成private(non-public)並設定getter
pst = [p1,p2]
for p in pst:
    if p._Pokemon__Name != p.Name: print('Property Error')
    if p._Pokemon__Lv != p.Lv: print('Property Error')
    if p._Pokemon__HpCur != p.HpCur: print('Property Error')
    if p._Pokemon__HpMax != p.HpMax: print('Property Error')
 
#不同版本的python自動解構的順序並不一定，手動刪除以維持穩定性
del pst
del p1
del p2