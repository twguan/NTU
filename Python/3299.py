def BD_Construction(Matrix_input,District):
    n = 0
    N = [0,0]
    S = [0,0]
    W = [0,100]
    E = [0,0]
    first = 1
    str = ''
    for i in range(len(Matrix_input)):
        for j in range(len(Matrix_input[0])):
            if (Matrix_input[i][j]=='1'):
                n += 1
                S[0] = i
                S[1] = j
            if (Matrix_input[i][j]=='1' and first):
                N[0] = i
                N[1] = j
                first = 0
            if (Matrix_input[i][j]=='1' and j < W[1]):
                W[0] = i
                W[1] = j
            if (Matrix_input[i][j]=='1' and j >= E[1]):
                E[0] = i
                E[1] = j
    if (n < 9):
        return 'None'
    else:
        str += 'District-' + District + '\n'
        str += 'N(%d,%d)\nS(%d,%d)\nW(%d,%d)\nE(%d,%d)'%(N[0],N[1],S[0],S[1],W[0],W[1],E[0],E[1])
        if (n >= 15):
            C = (round((N[0]+S[0])/2,0), round((W[1]+E[1])/2,0))
            str += '\nCommand center(%d,%d)'%(C[0],C[1])
        return str

gg = []
while True:
    temp = input().split()
    a = temp[0]
    temp[0] = '0'
    if (a.isalpha()):
        break
    gg.append(temp)
str = BD_Construction(gg, a)
print(str)