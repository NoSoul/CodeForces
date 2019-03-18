#include <stdio.h>

#define MAXV    10001

typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t E[MAXV * 2];
int Adj[MAXV];
int Size;
char Visit[MAXV];
int Queue[MAXV];

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

int main()
{
    int n, p;
    int C[MAXV];
    scanf("%d", &n);
    Init(n);
    for(int i = 2; i <= n; ++i) {
        scanf("%d", &p);

        Add_Edge(i, p);
        Add_Edge(p, i);
    }
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &C[i]);
    }
    int i, j, Head, Tail, Len = 0;
    Queue[Len++] = 1;
    Head = 0;
    Tail = 1;
    int ans = 1;
    Visit[1] = 1;
    while(Head < Tail) {
        for(i = Head; i < Tail; ++i) {
            for(j = Adj[Queue[i]]; ~j; j = E[j].next) {
                if(!Visit[E[j].to]) {
                    Visit[E[j].to] = 1;
                    Queue[Len++] = E[j].to;
                    if(C[E[j].to] != C[Queue[i]]) {
                        ++ans;
                    }
                }
            }
        }
        Head = Tail;
        Tail = Len;
    }
    printf("%d\n", ans);
    return 0;
}
