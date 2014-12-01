#include <stdio.h>

#define MAXV    51
#define MAXE    (MAXV*MAXV)

typedef struct
{
    int to;
    int next;
} Edge_t;
Edge_t E[MAXE];
int SizeE;
int Adj[MAXV];
char Visited[MAXV];
long long Ans = 1;

void Init(int N)
{
    int i;
    for(i = 0; i <= N; ++i)
    {
        Adj[i] = -1;
    }
    SizeE = 0;
}

void Add_Edge(int u, int v)
{
    E[SizeE].to = v;
    E[SizeE].next = Adj[u];
    Adj[u] = SizeE++;
}

void BFS(int start)
{
    int Queue[MAXV];
    int Head, Tail, Cnt, i, j;
    Head = 0;
    Tail = Cnt = 1;
    Visited[start] = 1;
    Queue[0] = start;
    while(Head < Tail)
    {
        for(i = Head; i < Tail; ++i)
        {
            for(j = Adj[Queue[i]]; ~j; j = E[j].next)
            {
                if(!Visited[E[j].to])
                {
                    Visited[E[j].to] = 1;
                    Queue[Cnt++] = E[j].to;
                }
            }
        }
        Head = Tail;
        Tail = Cnt;
    }
    while(Cnt > 1)
    {
        Ans = Ans * 2;
        --Cnt;
    }
}

int main()
{
    int N, M, i, x, y, Cnt;
    scanf("%d %d", &N, &M);
    Init(N);
    for(i = 0; i < M; ++i)
    {
        scanf("%d %d", &x, &y);
        --x;
        --y;
        Add_Edge(x, y);
        Add_Edge(y, x);
    }
    for(i = 0; i < N; ++i)
    {
        if(!Visited[i])
        {
            BFS(i);
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
