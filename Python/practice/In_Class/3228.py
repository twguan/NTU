def ReliefPackage(str1, str2):
    info = {'L':['中低收入戶','經濟弱勢之身障、老人、兒少','每人每月1500元，發放3個月共4500元','免申請，直接入戶'], 'N':['無相關社會保險者','未加入軍、公、教、勞、農保等社會保險者','可申請急難救助金1至3萬元','新申請者可於6月7日至30日期間線上或郵局申請'], 'S':['自營工作者／無一定雇主之勞工','加入勞保，年所得未達40萬8000','依月投保薪資領取3萬或1萬','新申請者，6/7起至勞保局官網辦理']}
    if str1 not in info:
        print('%s類別並不存在' % str1)
    else:
        if str2 == 'Object':
            print(info[str1][0])
            print('紓困對象：%s'%info[str1][1])
        elif str2 == 'Detail':
            print(info[str1][0])
            print('補助內容：%s'%info[str1][2])
        elif str2 == 'Pathway':
            print(info[str1][0])
            print('申請方式：%s'%info[str1][3])
        elif str2 == 'All':
            print(info[str1][0])
            print('紓困對象：%s'%info[str1][1])
            print('補助內容：%s'%info[str1][2])
            print('申請方式：%s'%info[str1][3])

if __name__ == '__main__':
    str1 = input()
    str2 = input()
    ReliefPackage(str1, str2)