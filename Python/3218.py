def flame_breathing(train, *num):
    for i in num:
        if (train[i-1] == 0):
            train[i-1] = -1
    return train

if __name__ == '__main__':
    m = int(input())
    s1, s2 = input().split()
    s1, s2 = int(s1), int(s2)

    train = []
    for i in range(1,m+1):
        if i == s1:
            train.append(1)
        elif i == s2:
            train.append(2)
        else:
            train.append(0)
    print(train)
    num_lst = [int(i) for i in input().split()]
    final_train = flame_breathing(train, *num_lst)
    print(final_train)