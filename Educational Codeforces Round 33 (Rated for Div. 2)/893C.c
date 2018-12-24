#include <stdio.h>
#include <string.h>

#define MAXV    100001

typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t E[MAXV << 1];
int Adj[MAXV];
int Size;
char Visit[MAXV];
int Queue[MAXV];
int C[MAXV];

void Init(int N)
{
    int i;
    for(i = 0; i <= N; ++i) {
        Adj[i] = -1;
    }
    Size = 0;
}

void Add_Edge(int u, int v)
{
    E[Size].to = v;
    E[Size].next = Adj[u];
    Adj[u] = Size++;
}

int BFS(int start)
{
    int i, j, Head, Tail, Len = 0;
    Queue[Len++] = start;
    Head = 0;
    Tail = 1;
    int ans = C[start];
    while(Head < Tail) {
        for(i = Head; i < Tail; ++i) {
            for(j = Adj[Queue[i]]; ~j; j = E[j].next) {
                if(!Visit[E[j].to]) {
                    if(ans > C[E[j].to]) {
                        ans = C[E[j].to];
                    }
                    Visit[E[j].to] = 1;
                    Queue[Len++] = E[j].to;
                }
            }
        }
        Head = Tail;
        Tail = Len;
    }
    return ans;
}

int main()
{
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    Init(n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &C[i]);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        Add_Edge(x, y);
        Add_Edge(y, x);
    }
    memset(Visit, 0, sizeof(Visit));
    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(!Visit[i]) {
            Visit[i] = 1;
            ans += BFS(i);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
