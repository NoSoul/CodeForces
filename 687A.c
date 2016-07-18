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
char Visit[MAXV];
int Queue[MAXV];

void Init()
{
    memset(Adj, -1, sizeof(Adj));
    Size = 0;
}

void AddDirectedEdge(int u, int v)
{
    E[Size].to = v;
    E[Size].next = Adj[u];
    Adj[u] = Size++;
}

void AddUndirectedEdge(int u, int v)
{
    AddDirectedEdge(u, v);
    AddDirectedEdge(v, u);
}

int BFS(int s)
{
    Visit[s] = 1;
    Queue[0] = s;
    int Head = 0, Tail = 1;
    while(Head < Tail) {
        for(int j = Adj[Queue[Head]]; ~j; j = E[j].next) {
            int expect = Visit[Queue[Head]] == 1 ? 2 : 1;
            if(Visit[E[j].to] && Visit[E[j].to] != expect) {
                return 1;
            }
            if(!Visit[E[j].to]) {
                Visit[E[j].to] = expect;
                Queue[Tail++] = E[j].to;
            }
        }
        ++Head;
    }
    return 0;
}

void Show(int n, int type)
{
    int cnt = 0;
    for(int i = 0; i <= n; ++i) {
        if(Visit[i] == type) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    for(int i = 0; i <= n; ++i) {
        if(Visit[i] == type) {
            printf("%d ", i);
        }
    }
    puts("");
}

int main()
{
    int n, m, u, v;
    Init();
    scanf("%d %d", &n, &m);
    while(m--) {
        scanf("%d %d", &u, &v);
        AddUndirectedEdge(u, v);
    }
    for(int i = 1; i <= n; ++i) {
        if(!Visit[i]) {
            if(BFS(i)) {
                puts("-1");
                return 0;
            }
        }
    }
    Show(n, 1);
    Show(n, 2);
    return 0;
}
