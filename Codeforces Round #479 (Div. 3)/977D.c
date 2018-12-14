#include <stdio.h>
#include <string.h>

#define MAXV    100
#define MAXE    (MAXV*MAXV)

typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t E[MAXE];
int SizeE;
int Adj[MAXV];
char Visited[MAXV];
long long A[100];

void Init(int N)
{
    int i;
    for(i = 0; i <= N; ++i) {
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

int BFS(int start, int n)
{
    int Queue[MAXV];
    int Head, Tail, Cnt, i, j;
    Head = 0;
    Tail = Cnt = 1;
    memset(Visited, 0, sizeof(Visited));
    Visited[start] = 1;
    Queue[0] = start;
    while(Head < Tail) {
        for(i = Head; i < Tail; ++i) {
            for(j = Adj[Queue[i]]; ~j; j = E[j].next) {
                if(!Visited[E[j].to]) {
                    Visited[E[j].to] = 1;
                    Queue[Cnt++] = E[j].to;
                }
            }
        }
        Head = Tail;
        Tail = Cnt;
    }
    if(Cnt == n) {
        for(int i = 0; i < n; ++i) {
            printf("%I64d ", A[Queue[i]]);
        }
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%I64d", &A[i]);
    }
    Init(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i != j) {
                if(A[i] == A[j] * 3) {
                    Add_Edge(i, j);
                }
                if(A[i] * 2 == A[j]) {
                    Add_Edge(i, j);
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(BFS(i, n)) {
            break;
        }
    }
    return 0;
}
