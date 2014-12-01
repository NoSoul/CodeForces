#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 100001
#define MAXE 200001

typedef struct
{
    int to, next;
} Edge;
Edge E[MAXE];
int Adj[MAXV], Size;

typedef struct
{
    int index, c;
} Value;
Value V[MAXV];
int A[MAXV];
int Res[MAXV], Len;

void Init(int N)
{
    int i;
    for(Size = i = 0; i <= N; ++i)
    {
        Adj[i] = -1;
    }
    return;
}

void Add_Edge(int u, int v)
{
    E[Size].to = v;
    E[Size].next = Adj[u];
    Adj[u] = Size++;
    return;
}

void _Add_Edge(int u, int v)
{
    Add_Edge(u, v);
    Add_Edge(v, u);
    return;
}

int cmp(const void *a, const void *b)
{
    if((*(Value *)a).c == (*(Value *)b).c)
    {
        return (*(Value *)a).index - (*(Value *)b).index;
    }
    return (*(Value *)a).c - (*(Value *)b).c;
}

void Find(int u)
{
    int i, j;
    for(i = Adj[u]; ~i; i = E[i].next)
    {
        for(j = 0; j < Len; ++j)
        {
            if(Res[j] == A[E[i].to])
            {
                break;
            }
        }
        if(j == Len)
        {
            Res[Len++] = A[E[i].to];
        }
    }
    return;
}

int main()
{
    int N, M, i, j, Max, Ans;
    scanf("%d %d", &N, &M);
    Init(N);
    for(i = 1; i <= N; ++i)
    {
        V[i].index = i;
        scanf("%d", &V[i].c);
        A[i] = V[i].c;
    }
    while(M--)
    {
        scanf("%d %d", &i, &j);
        if(V[i].c != V[j].c)
        {
            _Add_Edge(i, j);
        }
    }
    qsort(V + 1, N, sizeof(Value), cmp);
    Max = 0;
    for(i = 1; i <= N; i = j)
    {
        Len = 0;
        Res[Len++] = A[V[i].index];
        for(j = i; j <= N; ++j)
        {
            if(V[j].c != V[i].c)
            {
                break;
            }
            Find(V[j].index);
        }
        if(Len > Max)
        {
            Max = Len;
            Ans = V[i].c;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
