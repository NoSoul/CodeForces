#include <stdio.h>

#define MAXV    2001

typedef struct
{
    int to;
    int next;
} Edge_t;
Edge_t E[MAXV];
int Adj[MAXV];
int Size;
char Visit[MAXV];
int Queue[MAXV];

void Init(int N)
{
    int i;
    for(i = 0; i <= N; ++i)
    {
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
    int i, j, Head, Tail, res = 0, Len = 0;
    Queue[Len++] = start;
    Head = 0;
    Tail = 1;
    while(Head < Tail)
    {
        for(i = Head; i < Tail; ++i)
        {
            for(j = Adj[Queue[i]]; ~j; j = E[j].next)
            {
                Visit[E[j].to] = 1;
                Queue[Len++] = E[j].to;
            }
        }
        Head = Tail;
        Tail = Len;
        ++res;
    }
    return res;
}

int main()
{
    int N, i, Num, Ans;
    scanf("%d", &N);
    Init(N);
    for(i = 1; i <= N; ++i)
    {
        scanf("%d", &Num);
        if(~Num)
        {
            Add_Edge(Num, i);
        }
    }
    Ans = 0;
    for(i = 1; i <= N; ++i)
    {
        if(!Visit[i])
        {
            int Now = BFS(i);
            if(Now > Ans)
            {
                Ans = Now;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
