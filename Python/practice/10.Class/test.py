import Pokemon
 
name = input().strip()
lv = int(input())
hp = int(input())
p1 = Pokemon.Pokemon(name,lv,hp)
p1.ShowInfo()
del p1

name = input().strip()
lv = int(input())
hp = int(input())
p2 = Pokemon.Pokemon(name,lv,hp)
p3 = Pokemon.Pokemon()
 
p2.ShowInfo()
p3.ShowInfo()
 
#以下為測試是否將成員設成private(non-public)
private_tester = p3._Pokemon__Name
private_tester = p3._Pokemon__Lv
private_tester = p3._Pokemon__HpCur
private_tester = p3._Pokemon__HpMax
 
private_tester = p2._Pokemon__Name
private_tester = p2._Pokemon__Lv
private_tester = p2._Pokemon__HpCur
private_tester = p2._Pokemon__HpMax
 
del p3
del p2