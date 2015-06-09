#include <stdio.h>
#include <string.h>

#define MAXV    100
typedef struct {
    int to;
    int next;
    int c;
} Edge_t;
Edge_t E[MAXV << 1];
int Adj[MAXV], Size;
int Queue[MAXV];
char Visited[MAXV];

void Initialize()
{
    memset(Adj, -1, sizeof(Adj));
    Size = 0;
}

void AddEdge(int u, int v, int c)
{
    E[Size].to = v;
    E[Size].next = Adj[u];
    E[Size].c = c;
    Adj[u] = Size++;
}

int BFS(int u, int v, int c)
{
    int Head, Tail, Cnt;
    Head = 0;
    Tail = Cnt = 1;
    memset(Visited, 0, sizeof(Visited));
    Queue[0] = u;
    Visited[u] = 1;
    int i, j;
    while(Head < Tail) {
        for(i = Head; i < Tail; ++i) {
            for(j = Adj[Queue[i]]; ~j; j = E[j].next) {
                if(!Visited[E[j].to] && E[j].c == c) {
                    if(E[j].to == v) {
                        return 1;
                    }
                    Visited[E[j].to] = 1;
                    Queue[Cnt++] = E[j].to;
                }
            }
        }
        Head = Tail;
        Tail = Cnt;
    }
    return 0;
}

int main()
{
    Initialize();
    int N, M, Q, u, v, c, i;
    scanf("%d %d", &N, &M);
    for(i = 0; i < M; ++i) {
        scanf("%d %d %d", &u, &v, &c);
        --u;
        --v;
        --c;
        AddEdge(u, v, c);
        AddEdge(v, u, c);
    }
    scanf("%d", &Q);
    while(Q--) {
        scanf("%d %d", &u, &v);
        --u;
        --v;
        int Cnt = 0;
        for(i = 0; i < M; ++i) {
            if(BFS(u, v, i)) {
                ++Cnt;
            }
        }
        printf("%d\n", Cnt);
    }
    return 0;
}
