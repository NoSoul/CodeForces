#include <stdio.h>
#include <string.h>

#define MAXV    200001
#define MAXE    400001

typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t E[MAXE];
int Adj[MAXV];
int Size;
char Visit[MAXV];
int Queue[MAXV];

void Init()
{
    memset(Adj, -1, sizeof(Adj));
    Size = 0;
}

void Add_Edge(int u, int v)
{
    E[Size].to = v;
    E[Size].next = Adj[u];
    Adj[u] = Size++;
}

int main()
{
    Init();
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        Add_Edge(u, v);
        Add_Edge(v, u);
    }
    int ans = 0;
    int max = 1;
    for(int i = 1; i <= n; ++i) {
        if(!Visit[i] && i < max) {
            ++ans;
        }
        if(~Adj[i]) {
            int Len = 0;
            int Head = 0;
            int Tail = 1;
            Queue[Len++] = i;
            Visit[i] = 1;
            while(Head < Tail) {
                for(int k = Head; k < Tail; ++k) {
                    for(int j = Adj[Queue[k]]; ~j; j = E[j].next) {
                        if(!Visit[E[j].to]) {
                            Visit[E[j].to] = 1;
                            if(max < E[j].to) {
                                max = E[j].to;
                            }
                            Queue[Len++] = E[j].to;
                        }
                    }
                }
                Head = Tail;
                Tail = Len;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
