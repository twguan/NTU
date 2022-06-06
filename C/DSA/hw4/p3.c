#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long q = 0;
long long stack[1000000];
int ct = 0;

typedef struct save{
    int isMerge;
    int ta;
    int tb;
}save;

typedef struct ds{
    struct ds *parent;
    int num;
    int size;
}ds;

typedef struct node{
    int vertex;
    struct node *next;
}node;

typedef struct Graph{
    int numVertex;
    struct node ** list;
}Graph;

ds* createDs(int num){
    ds *newDs = malloc(sizeof(ds));
    newDs->parent = newDs;
    newDs->num = num;
    newDs->size = 1;

    return newDs;
}

int findSet(ds **sets, int i){
    while (sets[i]->parent != sets[i])
        i = sets[i]->parent->num;

    return sets[i]->num;
}

int merge(ds **sets, int ta, int tb, save *save){
    int a = findSet(sets, ta), b = findSet(sets, tb);
    if (a == b)     // merge failure
        return 0;

    else{
        save->ta = a;
        save->tb = b;
        if (sets[a]->size >= sets[b]->size){
            sets[b]->parent = sets[a];
            sets[a]->size += sets[b]->size;
            // return b -> a, a.size += b.size
        }
        else {
            sets[a]->parent = sets[b];
            sets[b]->size += sets[a]->size;
            // return a -> b, b.size += a.size
        }
    }
}

int reverse(ds **sets, int ta, int tb){
    int a = findSet(sets, ta), b = findSet(sets, tb);
    if (a == b){    //same set
        if (sets[ta]->size >= sets[tb]->size){
            sets[tb]->parent = sets[tb];
            sets[ta]->size -= sets[tb]->size;
            // return b -> a, a.size += b.size
        }
        else {
            sets[ta]->parent = sets[ta];
            sets[tb]->size -= sets[ta]->size;
            // return a -> b, b.size += a.size
        }
        return 1;
    }
    else
        return 0;
}


node* createNode(int v){
    node *newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numVertex){
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertex = numVertex;
    graph->list = malloc(sizeof(node *) * numVertex);

    for (int i = 0; i < numVertex; i++)
        graph->list[i] = NULL;

    return graph;
}

void addEdge(Graph *graph, int s, int d){
    // add s to d
    node* newNode = createNode(d);
    newNode->next = graph->list[s];
    graph->list[s] = newNode;

}

void traverse(Graph *graph ,node *node, save **record, ds **sets){
    if (node == NULL)
        return;
    while (node){
        int i = node->vertex;
        if (record[i]->isMerge == 1){    // merge
            if(merge(sets, record[i]->ta, record[i]->tb, record[i]))
                q--;
        }
        else if (record[i]->isMerge == 2)
            stack[ct++] = q;
        traverse(graph, graph->list[i], record, sets);
        if (record[i]->isMerge == 1){    // merge
            if(reverse(sets, record[i]->ta, record[i]->tb))
                q++;
        }
        node = node->next;
    }
}

void printDs(ds **sets, int n){
    for (int i = 1; i < n; i++)
        printf("ds %d: p= %d, size= %d\n", i, sets[i]->parent->num, sets[i]->size);
}

// void printGraph(Graph *graph){
//     for (int i = 0; i < graph->numVertex; i++){
//         node *temp = graph->list[i];
//         printf("vertex %d\n:", i);
//         while (temp){
//             printf("%d -> ", temp->vertex);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }

int main(){
    int N, M;
    char order[16];
    scanf("%d%d", &N, &M);
    q = N;
    Graph* graph = createGraph(M+1);
    ds **sets = malloc(sizeof(ds*) * N+1);
    for (int i = 0; i < N+1; i++)
        sets[i] = createDs(i);

    save **record = malloc(sizeof(save *) * M+1);
    for (int i = 1; i < M+1; i++){
        record[i] = malloc(sizeof(save));
        record[i]->isMerge = 0;
    }

    for (int i = 0; i < M; i++){
        scanf("%s", order);
        if (!strcmp(order, "merge")){
            int a, b;
            scanf("%d%d", &a, &b);
            addEdge(graph, i, i+1);
            record[i+1]->isMerge = 1;
            record[i+1]->ta = a;
            record[i+1]->tb = b;
        }
        else if (!strcmp(order, "query")){
            addEdge(graph, i, i+1);
            record[i+1]->isMerge = 2;
        }
        else if (!strcmp(order, "boom")){
            int a;
            scanf("%d", &a);
            addEdge(graph, a, i+1);
        }
    }
    // for (int i = 1; i < M+1; i++)
    //     printf("%d: M=%d, a:%d b:%d\n", i, record[i]->isMerge, record[i]->ta, record[i]->tb);
    // printDs(sets, N+1);
    // printGraph(graph);
    traverse(graph, graph->list[0], record, sets);
    for (int i = ct-1; i >= 0; i--)
        printf("%d\n", stack[i]);
    return 0;
}