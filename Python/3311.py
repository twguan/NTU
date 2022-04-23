def MatMul(A,B):
    C = []
    Bt = []
    for k in range(3):
        temp = []
        for i in range(3):
            num = 0
            for j in range(3):
                num += A[k][j] * B[j][i]
            temp.append(num)
        C.append(temp)
    return C

def Transform(x, A):
    vecter = []
    for i in range(len(A)):
        temp = 0
        for j in range(len(x)):
            temp += A[i][j] * x[j]
        vecter.append(temp)
    return vecter

def Transpose(A):
    C = []
    for i in range(len(A)):
        temp = []
        for j in range(len(A[0])):
            temp.append(A[j][i])
        C.append(temp)
    return C

def Determinant(A):
    num = 0
    dA = [[[A[1][1],A[1][2]],[A[2][1],A[2][2]]],[[A[1][0],A[1][2]],[A[2][0],A[2][2]]],[[A[1][0],A[1][1]],[A[2][0],A[2][1]]]]
    minus = 1
    for i in range(len(A)):
        num += A[0][i] * det2D(dA[i]) * minus
        minus *= -1
    return num

def det2D(A):
    return(A[0][0]*A[1][1] - A[0][1]*A[1][0])