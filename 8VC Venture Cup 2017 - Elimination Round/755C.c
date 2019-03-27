#include <stdio.h>
#include <string.h>

#define MAXV    10001

typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t E[MAXV << 1];
int Adj[MAXV];
int Size;
char Visit[MAXV];
int Queue[MAXV];

void Init(int N)
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

void BFS(int start)
{
    int j, Head, Tail;
    Head = Tail = 0;
    Visit[start] = 1;
    Queue[Tail++] = start;
    while(Head < Tail) {
        for(j = Adj[Queue[Head]]; ~j; j = E[j].next) {
            if(!Visit[E[j].to]) {
                Visit[E[j].to] = 1;
                Queue[Tail++] = E[j].to;
            }
        }
        ++Head;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Init(n);
    for(int i = 1; i <= n; ++i) {
        int p;
        scanf("%d", &p);
        Add_Edge(i, p);
        Add_Edge(p, i);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(!Visit[i]) {
            BFS(i);
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
