#include <stdio.h>
#include <string.h>

#define  MAXV 100002
#define  MAXE 200002

typedef struct {
    int to, value, next;
} Edge;
Edge E[MAXE];

int Adj[MAXV], Path[MAXV], Visited[MAXV], Queue[MAXV];
long long Dist[MAXV];
int Size;

void Init()
{
    memset(Adj, -1, sizeof(Adj));
    memset(Path, -1, sizeof(Path));
    memset(Visited, 0, sizeof(Visited));
    memset(Dist, 0x7f, sizeof(Dist));
    Size = 0;
}

void AddEdge(int from, int to, int value)
{
    E[Size].to = to;
    E[Size].value = value;
    E[Size].next = Adj[from];
    Adj[from] = Size++;
}

void SPFA(int start)
{
    int i, head, tail, now;
    head = Dist[start] = 0;
    tail = Visited[start] = 1;
    Queue[head] = start;
    while(head != tail) {
        now = Queue[head];
        for(i = Adj[now]; ~i; i = E[i].next) {
            if(Dist[E[i].to] - Dist[now] > E[i].value) {
                Dist[E[i].to] = Dist[now] + E[i].value;
                Path[E[i].to] = now;
                if(!Visited[E[i].to]) {
                    Visited[E[i].to] = 1;
                    Queue[tail] = E[i].to;
                    tail = (tail + 1) % MAXV;
                }
            }
        }
        head = (head + 1) % MAXV;
        Visited[now] = 0;
    }
    return;
}

int main()
{
    Init();
    int n, m, a, b, w;
    scanf("%d %d", &n, &m);
    while(m--) {
        scanf("%d %d %d", &a, &b, &w);
        AddEdge(a, b, w);
        AddEdge(b, a, w);
    }
    SPFA(1);
    if(Path[n] == -1) {
        puts("-1");
    } else {
        Size = 0;
        int p = n;
        Queue[Size++] = p;
        while(p != 1) {
            p = Path[p];
            Queue[Size++] = p;
        }
        for(int i = Size - 1; i >= 0; --i) {
            printf("%d ", Queue[i]);
        }
        puts("");
    }
    return 0;
}
