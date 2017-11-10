#include <stdio.h>
#include <string.h>

#define MAXV    100001
#define MAXE    (MAXV*2)

typedef struct {
    int to, next;
} Edge_t;
Edge_t E[MAXE];
int Adj[MAXV], Visit[MAXV], Queue[MAXV];
double Probability[MAXV];
int Size;

void Init()
{
    memset(Adj, -1, sizeof(Adj));
    memset(Visit, 0, sizeof(Visit));
    Size = 0;
}

void AddEdge(int from, int to)
{
    E[Size].to = to;
    E[Size].next = Adj[from];
    Adj[from] = Size++;
}

double BFS(int s)
{
    int head, tail, cur, step;
    head = tail = 0;
    Visit[s] = 1;
    Queue[tail++] = s;
    cur = tail;
    step = 0;
    Probability[s] = 1;
    double ret = 0;
    while(head < tail) {
        for(int i = head; i < tail; ++i) {
            int u = Queue[i];
            char leaf = 1;
            int p = 0;
            for(int j = Adj[u]; ~j; j = E[j].next) {
                int v = E[j].to;
                if(!Visit[v]) {
                    ++p;
                }
            }
            for(int j = Adj[u]; ~j; j = E[j].next) {
                int v = E[j].to;
                if(!Visit[v]) {
                    leaf = 0;
                    Visit[v] = 1;
                    Queue[cur++] = v;
                    Probability[v] = Probability[u] / p;
                }
            }
            if(leaf) {
                ret += Probability[u] * step;
            }
        }
        head = tail;
        tail = cur;
        ++step;
    }
    return ret;
}

int main()
{
    int n;
    Init();
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    printf("%lf\n", BFS(1));
    return 0;
}
