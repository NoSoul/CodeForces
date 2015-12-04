#include <stdio.h>
#include <string.h>

#define MAXV    401

typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t ERoad[MAXV * MAXV];
Edge_t ERail[MAXV * MAXV];
int AdjRoad[MAXV];
int AdjRail[MAXV];
int SizeRoad, SizeRail;
int Queue[MAXV];
char Visited[MAXV];

char Flag[MAXV][MAXV];

void Initialize()
{
    memset(AdjRoad, -1, sizeof(AdjRoad));
    memset(AdjRail, -1, sizeof(AdjRail));
}

void AddEdge(int u, int v, char road)
{
    if(road) {
        ERoad[SizeRoad].to = v;
        ERoad[SizeRoad].next = AdjRoad[u];
        AdjRoad[u] = SizeRoad++;
    } else {
        ERail[SizeRail].to = v;
        ERail[SizeRail].next = AdjRail[u];
        AdjRail[u] = SizeRail++;
    }
}

int BFS(int u, int v, Edge_t *E, int *Adj)
{
    int Head, Tail, Cnt, i, j;
    Head = 0;
    Tail = Cnt = 1;
    memset(Visited, 0, sizeof(Visited));
    Queue[0] = u;
    Visited[u] = 1;
    int Ans = 1;
    while(Head < Tail) {
        for(i = Head; i < Tail; ++i) {
            for(j = Adj[Queue[i]]; ~j; j = E[j].next) {
                if(!Visited[E[j].to]) {
                    if(E[j].to == v) {
                        return Ans;
                    }
                    Visited[E[j].to] = 1;
                    Queue[Cnt++] = E[j].to;
                }
            }
        }
        Head = Tail;
        Tail = Cnt;
        ++Ans;
    }
    return -1;
}

int main()
{
    int N, M, u, v, i, j;
    Initialize();
    scanf("%d %d", &N, &M);
    while(M--) {
        scanf("%d %d", &u, &v);
        Flag[u][v] = Flag[v][u] = 1;
        AddEdge(u, v, 0);
        AddEdge(v, u, 0);
    }
    for(i = 1; i <= N; ++i) {
        for(j = i + 1; j <= N; ++j) {
            if(!Flag[i][j]) {
                AddEdge(i, j, 1);
                AddEdge(j, i, 1);
            }
        }
    }
    if(Flag[1][N]) {
        printf("%d\n", BFS(1, N, ERoad, AdjRoad));
    } else {
        printf("%d\n", BFS(1, N, ERail, AdjRail));
    }
    return 0;
}
