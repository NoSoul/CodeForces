#include <stdio.h>
#include <string.h>

#define  MAXN 210

typedef struct {
    int v, next;
} Edge;
Edge E[MAXN];
int Adj[MAXN], Size;
int Visit[MAXN], View[MAXN], In[MAXN];


void Init(int N)
{
    int i;
    for(Size = i = 0; i <= N; ++i) {
        Adj[i] = -1;
        View[i] = In[i] = 0;
    }
    return;
}

void Add_Edge(int u, int v)
{
    E[Size].v = v;
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

int Judge(int u, int v)
{
    int Head, Tail, i, j, k, Cnt = 0;
    int Queue[MAXN];
    Head = 0;
    Queue[0] = u;
    Cnt = k = Tail = Visit[u] = 1;
    while(Head < Tail) {
        for(i = Head; i < Tail; ++i) {
            for(j = Adj[Queue[i]]; ~j; j = E[j].next) {
                if(!Visit[E[j].v] && !View[E[j].v]) {
                    Visit[E[j].v] = 1;
                    if(E[j].v == v) {
                        if(Cnt % 2) {
                            return 1;
                        }
                        return 0;
                    }
                    Queue[k++] = E[j].v;
                }
            }
            ++Cnt;
            Head = Tail;
            Tail = k;
        }
    }
    return 0;
}

int main()
{
    int N, M, u, v, i, j, A, B, R, Cnt;
    scanf("%d %d", &N, &M);
    Init(N);
    while(M--) {
        scanf("%d %d", &u, &v);
        _Add_Edge(u, v);
        ++In[u];
        ++In[v];
    }
    for(Cnt = 0, i = 1; i <= N; ++i) {
        if(!View[i] && In[i] == 2) {
            View[i] = 1;
            j = Adj[i];
            A = E[j].v;
            j = E[j].next;
            B = E[j].v;
            memset(Visit, 0, sizeof(Visit));
            R = Judge(A, B);
            if(R) {
                View[A] = View[B] = 1;
                ++Cnt;
            }
        }
    }
    N -= Cnt;
    if(N % 2) {
        ++Cnt;
    }
    printf("%d\n", Cnt);
    return 0;
}
