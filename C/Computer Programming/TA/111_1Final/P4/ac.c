#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player{
    char name[64];
    int position;   // 0: goal keeper, 1: player
    double ability; // 0-100
    int order[5];   // 0: middle, 1: left, 2: right
}Player;

void Team_Init(Player *P){
    for (int i = 0; i < 11; ++i){
        scanf("%s ", P[i].name);
        scanf("%d%lf", &P[i].position, &P[i].ability);
        for (int j = 0; j < 5; ++j)
            scanf("%d", &P[i].order[j]);
    }
};

int cmp(const void *a, const void *b){
    Player *pa, *pb;
    pa = (Player *)a;
    pb = (Player *)b;
    return (pa->position == pb->position) ? (int)(pb->ability - pa->ability) : (pa->position - pb->position);
}

void show(Player *PA, Player *PB, Player ka, Player kb){
    printf("\n        goal keeper for A & B\n");
    printf("%-12s %5.1lf | %-12s %5.1lf\n", ka.name, ka.ability, kb.name, kb.ability);
    printf("defence :  ");
    for (int i = 0; i < 5; ++i)
        printf("%d ", ka.order[i] );
    printf("|");
    for (int i = 0; i < 5; ++i)
        printf("%d ", kb.order[i] );


    printf("\n\n          players for A & B\n");
    for (int i = 0; i < 5; ++i){
        printf("%-12s %5.1lf %d | %-12s %5.1lf %d\n", PA[i].name, PA[i].ability, PA[i].order[i], PB[i].name, PB[i].ability, PB[i].order[i]);
    }
    printf("\n");
}

int main(){
    char teamA_Name[64], teamB_Name[64];
    Player A[11], B[11];
    scanf("%s ", teamA_Name);
    Team_Init(A);
    scanf("%s ", teamB_Name);
    Team_Init(B);

    qsort(A, 11, sizeof(A[0]), cmp);
    qsort(B, 11, sizeof(B[0]), cmp);

    Player A_keeper, B_keeper, A_player[5], B_player[5];
    A_keeper = A[0];
    B_keeper = B[0];
    for (int i = 0; i < 5; ++i){
        A_player[i] = A[i+1];
        B_player[i] = B[i+1];
    }
    // show(A_player, B_player, A_keeper, B_keeper);
    // kick
    int a_score = 0, b_score = 0;
    for (int i = 0; i < 5; ++i){
        // A Team kick
        double A_ability = A_player[i].ability;
        if (i == 0 || i == 4)
            A_ability *= 0.9;

        if (B_keeper.order[i] == A_player[i].order[i]){
            if (B_keeper.ability >= A_ability)
                printf("%s Get Blocked!\n", A_player[i].name);
            else{
                printf("%s Goal!\n", A_player[i].name);
                a_score++;
            }
        }
        else if (A_ability < 70)
            printf("%s Miss!\n", A_player[i].name);
        else{
            printf("%s Goal!\n", A_player[i].name);
            a_score++;
        }

        // early stop
        if (a_score > b_score + 5-i){
            printf("%s %d:%d win!\n", teamA_Name, a_score, b_score);
            break;
        }
        if (a_score + 4-i < b_score){
            printf("%s %d:%d win!\n", teamB_Name, a_score, b_score);
            break;
        }

        // B Team kick
        double B_ability = B_player[i].ability;
        if (i == 0 || i == 4)
            B_ability *= 0.9;

        if (A_keeper.order[i] == B_player[i].order[i]){
            if (A_keeper.ability >= B_ability)
                printf("%s Get Blocked!\n", B_player[i].name);
            else{
                printf("%s Goal!\n", B_player[i].name);
                b_score++;
            }
        }
        else if (B_ability < 70)
            printf("%s Miss!\n", B_player[i].name);
        else {
            printf("%s Goal!\n", B_player[i].name);
            b_score++;
        }
        
        printf("After %d round, the score is %d:%d\n\n", i+1, a_score, b_score);

        // early stop
        if (a_score > b_score + 4-i){
            printf("%s %d:%d win!\n", teamA_Name, a_score, b_score);
            break;
        }
        if (b_score > a_score + 4-i){
            printf("%s %d:%d win!\n", teamB_Name, a_score, b_score);
            break;
        }
        if (i == 4){
            if (a_score > b_score)
                printf("%s ", teamA_Name);
            else if (a_score < b_score)
                printf("%s ", teamB_Name);
            else
                printf("Draw ");
            printf("%d:%d\n", a_score, b_score);
        }
    }

    return 0;
}