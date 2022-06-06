#include <stdio.h>
#include <stdlib.h> // malloc / free
#include <memory.h> // memset
#include <stdbool.h>

// flag = 1 => upload judge
int flag = 1;
int N, M;
char *op;
int **op_num;
int *visited;
int *record;

typedef struct disjointSet
{
    int parent, size;
} DisjointSet;

typedef struct node
{
    int day;
    struct node *nxt;
} node;

DisjointSet *ds;
node **boom_day;

void makeset(int x)
{
    // create a set with one element
    ds[x].parent = x;
    ds[x].size = 1;
    // set[x] = 1;
}

int find_set(int x)
{
    // if (!set[x])
    //     makeset(x);

    while (x != ds[x].parent)
    {
        x = ds[x].parent;
    }
    return x;
}

void group(int a, int b, int day)
{
    // if a and b are not in the same set → union
    int x = find_set(a);
    int y = find_set(b);
    if (x != y)
    {
        N--;
        // weighted union
        if (ds[x].size >= ds[y].size)
        {
            record[day] = y;
            ds[y].parent = x;
            ds[x].size += ds[y].size;
        }
        else
        {
            record[day] = x;
            ds[x].parent = y;
            ds[y].size += ds[x].size;
        }
    }
}

void Reverse(int now, int past)
{
    for (int i = now; i > past; i--)
    {
        if (record[i] != 0)
        {
            int x = find_set(record[i]);
            ds[record[i]].parent = record[i];
            ds[x].size -= ds[record[i]].size;
            N++;
        }
    }
}

void Operations(int day)
{
    if (op[day] == 'm')
        group(op_num[day][0], op_num[day][1], day);
    else if (op[day] == 'q')
        op_num[day][0] = N;
    visited[day] = 1;
}

void DFS(int root)
{
    visited[root] = 1;
    while (boom_day[root] != NULL)
    {
        int current = boom_day[root]->day;
        if (boom_day[current] != NULL)
            DFS(current);
        current++;
        while (current <= M && op[current] != 'b')
        {
            Operations(current);
            if (boom_day[current] != NULL)
                DFS(current);
            current++;
        }
        Reverse(current - 1, boom_day[root]->day);
        boom_day[root] = boom_day[root]->nxt;
    }
}

int main()
{
    FILE *fp;
    if (flag)
        scanf("%d %d", &N, &M);
    else
    {
        fp = fopen("D:\\nick\\Homework\\Senior\\DSA\\Homework\\b07501117\\10\\test\\2.in", "r");
        fscanf(fp, "%d %d", &N, &M);
    }

    // set = malloc(sizeof(bool) * (N + 1));
    ds = malloc(sizeof(DisjointSet) * (N + 1));
    op = malloc(sizeof(char) * (M + 1));
    op_num = malloc(sizeof(int *) * (M + 1));
    record = malloc(sizeof(int) * (M + 1));
    visited = malloc(sizeof(int) * (M + 1));
    boom_day = malloc(sizeof(node *) * (M + 1));

    for (int n = 0; n <= N; n++)
        makeset(n);

    for (int m = 0; m <= M; m++)
    {
        op_num[m] = malloc(sizeof(int) * 2);
        boom_day[m] = NULL;
        record[m] = 0;
        visited[m] = 0;
    }
    visited[0] = 1;

    // read input / adjacent list
    char input[6];
    int A, B, past;
    for (int m = 1; m <= M; m++)
    {
        if (flag)
            scanf("%s", input);
        else
            fscanf(fp, "%s", input);
        op[m] = input[0];

        if (input[0] == 'm')
        {
            if (flag)
                scanf("%d %d", &A, &B);
            else
                fscanf(fp, "%d %d", &A, &B);
            op_num[m][0] = A;
            op_num[m][1] = B;
        }
        else if (input[0] == 'b')
        {
            if (flag)
                scanf("%d", &past);
            else
                fscanf(fp, "%d", &past);
            op_num[m][0] = past;
            node *tmp = malloc(sizeof(node));
            tmp->day = m;
            tmp->nxt = boom_day[past];
            boom_day[past] = tmp;
        }
    }

    for (int m = 0; m <= M; m++)
    {
        if (!visited[m])
            Operations(m);
        if (boom_day[m] != NULL)
            DFS(m);
    }

    for (int m = 1; m <= M; m++)
    {
        if (op[m] == 'q')
            printf("%d\n", op_num[m][0]);
    }

    if (!flag)
        fclose(fp);

    return 0;
}