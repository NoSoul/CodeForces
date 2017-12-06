#include <stdio.h>
#include <string.h>

#define MAXV 100001
#define MAXE (MAXV<<1)

typedef struct {
    int from, to, next;
} Edge_t;
Edge_t E[MAXE];
int Adj[MAXV], Visit[MAXV], Queue[MAXV];
int Size;
int Color[MAXV];

void Init()
{
    memset(Adj, -1, sizeof(Adj));
    memset(Visit, 0, sizeof(Visit));
    Size = 0;
}

void AddEdge(int from, int to)
{
    E[Size].from = from;
    E[Size].to = to;
    E[Size].next = Adj[from];
    Adj[from] = Size++;
}

int Fun(int u)
{
    int head, tail;
    memset(Visit, 0, sizeof(Visit));
    Visit[u] = 1;
    head = 0;
    tail = 1;
    Queue[head] = u;
    while(head < tail) {
        for(int i = Adj[Queue[head]]; ~i; i = E[i].next) {
            if(!Visit[E[i].to]) {
                if(head) {
                    if(Color[E[i].from] != Color[E[i].to]) {
                        return 1;
                        break;
                    }
                }
                Visit[E[i].to] = 1;
                Queue[tail++] = E[i].to;
            }
        }
        ++head;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    Init();
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u;
        --v;
        AddEdge(u, v);
        AddEdge(v, u);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &Color[i]);
    }
    char findTwo = 0;
    for(int i = 0; i < Size; ++i) {
        if(Color[E[i].from] != Color[E[i].to]) {
            findTwo = 1;
            if(!Fun(E[i].from)) {
                printf("YES\n%d\n", E[i].from + 1);
                return 0;
            }
            if(!Fun(E[i].to)) {
                printf("YES\n%d\n", E[i].to + 1);
                return 0;
            }
            break;
        }
    }
    puts(findTwo ? "NO" : "YES\n1");
    return 0;
}
