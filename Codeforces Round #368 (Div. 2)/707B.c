#include <stdio.h>
#include <string.h>
#define MAXN 100001

typedef struct {
    int to;
    int val;
    int next;
} Edge_t;
Edge_t E[MAXN << 1];
int Adj[MAXN];
int Size;

char Flag[MAXN];

void AddEdge(int u, int v, int l)
{
    E[Size].to = v;
    E[Size].val = l;
    E[Size].next = Adj[u];
    Adj[u] = Size++;
}

int main()
{
    int n, m, k, u, v, l, a;
    memset(Adj, -1, sizeof(Adj));
    scanf("%d %d %d", &n, &m, &k);
    while(m--) {
        scanf("%d %d %d", &u, &v, &l);
        AddEdge(u, v, l);
        AddEdge(v, u, l);
    }
    for(int i = 0; i < k; ++i) {
        scanf("%d", &a);
        Flag[a] = 1;
    }
    int Ans = -1;
    for(int i = 1; i <= n; ++i) {
        if(!Flag[i]) {
            for(int j = Adj[i]; ~j; j = E[j].next) {
                int v = E[j].to;
                if(Flag[v]) {
                    if(Ans == -1 || Ans > E[j].val) {
                        Ans = E[j].val;
                    }
                }
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
