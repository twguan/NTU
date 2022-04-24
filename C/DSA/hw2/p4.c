#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int index;
    struct node *next;
}node;

typedef struct list{
    int nodenum;
    node **adjlist;
}list;


node *CreateNode(int index){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->index = index;
    newNode->next = NULL;
    return newNode;
}

list *CreateList(int nodenum){
    list *List = malloc(sizeof(list));
    List->nodenum = nodenum;
    List->adjlist = malloc(sizeof(node *) * (nodenum));
    for (int i = 0; i < nodenum; i++)
        List->adjlist[i] = NULL;

    return List;
}

void addlink(list *List, int a, int b){

    // add b -> a
    node *newNode = CreateNode(b);
    newNode->next = List->adjlist[a];
    List->adjlist[a] = newNode;

    // add a -> b
    newNode = CreateNode(a);
    newNode->next = List->adjlist[b];
    List->adjlist[b] = newNode;
}

void printList(list *List){
    node *ptr;
    for (int i = 0; i < List->nodenum; i++){
        printf("node %d\n", i);
        ptr = List->adjlist[i];
        while (ptr != NULL){
            printf("%d->", ptr->index);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int earlystop = 0;
void DFS(list *List, int *traverse, int *parent, int visit, int goal){

        // printf("T%d ", visit);
        int next;
        node *ptr;
        traverse[visit] = 1;
        ptr = List->adjlist[visit];

        while (ptr != NULL){
            next = ptr->index;
            parent[next] = visit;
            if (next == goal){          // find the goal
                // printf("Find!");
                earlystop = 1;
                break;
            }
            if (earlystop)
                break;
            if (!traverse[next]){       // haven't traverse yet
                DFS(List, traverse, parent, next, goal);
            }
            else
                ptr = ptr->next;
        }
}

int familyList(int *parent, int son, int *list){
    int ct = 0;
    list[ct] = son;
    while (son){
        ct++;
        son = parent[son];
        list[ct] = son;
    }
    return ct;
}

int find(int *pathS, int *pathR, int lenS, int lenR){
    int n = 0;
    while (lenS && lenR){
        if (pathR[lenR-1] == pathS[lenS -1])
            n = pathR[lenR-1];
        lenR--;
        lenS--;
    }
    return n;
}

int main(){
    int N, Q, R, S, a, b, c;
    scanf("%d%d%d%d", &N, &Q, &R, &S);
    
    list *List = CreateList(N+1);
    for (int i = 0; i < N-1; i++){
        scanf("%d%d", &a, &b);
        addlink(List, a, b);
    }
    
    // build the tree that root is c;
    // memory the parent node
    for (int j = 0; j < Q; j++){
        scanf("%d", &c);

        int *traverse = (int *)malloc(sizeof(int) * (N+1));
        int *parent = (int *)malloc(sizeof(int) * (N+1));
        int *pathS = (int *)malloc(sizeof(int) * (N+1));
        int *pathR = (int *)malloc(sizeof(int) * (N+1));
        for (int i = 0; i < N+1; i++){
            parent[i] = 0;
            traverse[i] = 0;
            pathS[i] = 0;
            pathR[i] = 0;
        }
        earlystop = 0;
        DFS(List, traverse, parent, c, S);
        // printList(List);
        earlystop = 0;
        for (int i = 0; i < N+1; i++)
            traverse[i] = 0;
        DFS(List, traverse, parent, c, R);
        parent[c] = 0;
        int lenS, lenR;
        lenS = familyList(parent, S, pathS);
        lenR = familyList(parent, R, pathR);
        // for (int i = 0; i < N+1; i++)
        //     printf("%d parent is %d\n", i, parent[i]);
        // printf("pathR:\n");
        // for (int i = 0; i < N+1; i++)
        //     if (pathR[i])
        //         printf("%d->", pathR[i]);
        // printf("\npathS:\n");
        // for (int i = 0; i < N+1; i++)
        //     if (pathS[i])
        //         printf("%d->", pathS[i]);
        // printf("\n");
        printf("%d\n", find(pathS, pathR, lenS, lenR));
        free(traverse);
        free(parent);
        free(pathR);
        free(pathS);
    }
    return 0;
}