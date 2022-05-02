int safe(int array[5][5]){
    int move[4] = {0};
    int posx = 0, posy = 0;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (array[i][j] == 2){
                posx = j;
                posy = i;
            }
    int x = posx, y = posy;
    while (y >= 0 && array[y][x] != 1){
        move[0]++;
        y--;
        if (y < 0)
            move[0] = 1000;
    }
    x = posx;
    y = posy;
    while (x < 5 && array[y][x] != 1){
        move[1]++;
        x++;
        if (x == 5)
            move[1] = 1000;
    }
    x = posx;
    y = posy;
    while (y < 5 && array[y][x] != 1){
        move[2]++;
        y++;
        if (y == 5)
            move[2] = 1000;
    }
    x = posx;
    y = posy;
    while (x >= 0 && array[y][x] != 1){
        move[3]++;
        x--;
        if (x < 0)
            move[3] = 1000;
    }
    int min = 5, pos = 0;
    for (int i = 0; i < 4; ++i){
        if (min > move[i]){
            min = move[i];
            pos = i;
        }
    }
    int direction = pos+1;
    return direction;
}