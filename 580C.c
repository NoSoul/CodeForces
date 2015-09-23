#include <stdio.h>
#include <string.h>
#define MAXV    200001
#define MAXE    400001

typedef struct {
    int to;
    int next;
} Edege_t;
Edege_t E[MAXE];
int Adj[MAXV];
int Size;
char CatFlag[MAXV];
int CatCnt[MAXV];
char Visit[MAXV];

void Init()
{
    memset(Adj, -1, sizeof(Adj));
    Size = 0;
}

void AddEdge(int u, int v)
{
    E[Size].to = v;
    E[Size].next = Adj[u];
    Adj[u] = Size++;
}

int main()
{
    int N, M, i, x, y, Ans = 0;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; ++i) {
        scanf("%hhd", &CatFlag[i]);
    }
    Init();
    for(i = 0; i < N - 1; ++i) {
        scanf("%d %d", &x, &y);
        AddEdge(x, y);
        AddEdge(y, x);
    }
    CatCnt[1] = CatFlag[1];
    Visit[1] = 1;
    int Queue[MAXV];
    int Head = 0, Tail = 1;
    Queue[0] = 1;
    while(Head < Tail) {
        char leaf = 1;
        for(i = Adj[Queue[Head]]; ~i; i = E[i].next) {
            if(!Visit[E[i].to]) {
                leaf = 0;
                Visit[E[i].to] = 1;
                if(CatFlag[E[i].to] || CatCnt[Queue[Head]] > M) {
                    CatCnt[E[i].to] = CatCnt[Queue[Head]] + CatFlag[E[i].to];
                } else {
                    CatCnt[E[i].to] = 0;
                }
                Queue[Tail++] = E[i].to;
            }
        }
        if(leaf && CatCnt[Queue[Head]] <= M) {
            ++Ans;
        }
        ++Head;
    }
    printf("%d\n", Ans);
    return 0;
}
