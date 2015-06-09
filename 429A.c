#include <stdio.h>
#include <string.h>

#define MAXV 100000
typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t E[MAXV << 1];
int Adj[MAXV], Size;
char init[MAXV], goal[MAXV];
int Father[MAXV];
char Change[MAXV];
char Visited[MAXV];
int Queue[MAXV];
int AnsList[MAXV];
int AnsLen;

void Initialize()
{
    memset(Father, -1, sizeof(Father));
    memset(Adj, -1, sizeof(Adj));
    Size = 0;
}

void AddEdge(int u, int v)
{
    E[Size].to = v;
    E[Size].next = Adj[u];
    Adj[u] = Size++;
}

void BFS(int start)
{
    int Head, Tail, Cnt;
    Head = 0;
    Tail = Cnt = 1;
    Queue[0] = start;
    Visited[start] = 1;
    int i, j;
    while(Head < Tail) {
        for(i = Head; i < Tail; ++i) {
            for(j = Adj[Queue[i]]; ~j; j = E[j].next) {
                if(!Visited[E[j].to]) {
                    Visited[E[j].to] = 1;
                    Queue[Cnt++] = E[j].to;
                    Father[E[j].to] = Queue[i];
                    if(~Father[Queue[i]]) {
                        if(Change[Father[Queue[i]]]) {
                            init[E[j].to] ^= 1;
                        }
                    }
                    if(~Father[Queue[i]]) {
                        Change[E[j].to] = Change[Father[Queue[i]]];
                    }
                    if(init[E[j].to] != goal[E[j].to]) {
                        Change[E[j].to] ^= 1;
                        AnsList[AnsLen++] = E[j].to;
                    }
                }
            }
        }
        Head = Tail;
        Tail = Cnt;
    }
}

int main()
{
    int N, i, u, v;
    scanf("%d", &N);
    Initialize();
    for(i = 0; i < N - 1; ++i) {
        scanf("%d %d", &u, &v);
        --u;
        --v;
        AddEdge(u, v);
        AddEdge(v, u);
    }
    for(i = 0; i < N; ++i) {
        scanf("%d", &init[i]);
    }
    for(i = 0; i < N; ++i) {
        scanf("%d", &goal[i]);
    }
    if(init[0] != goal[0]) {
        Change[0] = 1;
        AnsList[AnsLen++] = 0;
    }
    BFS(0);
    printf("%d\n", AnsLen);
    for(i = 0; i < AnsLen; ++i) {
        printf("%d\n", AnsList[i] + 1);
    }
    return 0;
}
