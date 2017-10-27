#include <stdio.h>
#include <string.h>

typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t E[8001];
int Adj[4001];
int Size;
int D[4001];

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
    scanf("%d %d", &N, &M);
    Init();
    while(M--) {
        scanf("%d %d", &u, &v);
        ++D[u];
        ++D[v];
        AddEdge(u, v);
        AddEdge(v, u);
    }
    int Ans = 0x7fffffff;
    int i, j, k, ii;
    for(i = 1; i <= N; ++i) {
        for(u = Adj[i]; ~u; u = E[u].next) {
            j = E[u].to;
            for(v = Adj[j]; ~v; v = E[v].next) {
                k = E[v].to;
                char flag = 0;
                for(ii = Adj[k]; ~ii; ii = E[ii].next) {
                    if(E[ii].to == i) {
                        flag = 1;
                        break;
                    }
                }
                if(flag) {
                    if(D[i] + D[j] + D[k] - 6 < Ans) {
                        Ans = D[i] + D[j] + D[k] - 6;
                    }
                }
            }
        }
    }
    if(Ans == 0x7fffffff) {
        Ans = -1;
    }
    printf("%d\n", Ans);
    return 0;
}
