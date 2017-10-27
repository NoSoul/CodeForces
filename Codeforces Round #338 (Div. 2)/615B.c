#include <stdio.h>
#include <string.h>

#define MAXV    100001
#define MAXE    200001
typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t E[MAXE];
int Adj[MAXV];
int Size;
int Spines[MAXV];
int Tail[MAXV];

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
    int N, M, u, v;
    long long Ans = 0;
    scanf("%d %d", &N, &M);
    Init();
    while(M--) {
        scanf("%d %d", &u, &v);
        int temp;
        if(u > v) {
            temp = u;
            u = v;
            v = temp;
        }
        Tail[u] = 1;
        Tail[v] = 1;
        ++Spines[u];
        ++Spines[v];
        AddEdge(u, v);
    }
    int i, j;
    for(i = 1; i <= N; ++i) {
        for(j = Adj[i]; ~j; j = E[j].next) {
            if((Tail[i] + 1) > Tail[E[j].to]) {
                Tail[E[j].to] = Tail[i] + 1;
            }
        }
        long long Cur = (long long)Tail[i] * Spines[i];
        if(Cur > Ans) {
            Ans = Cur;
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
