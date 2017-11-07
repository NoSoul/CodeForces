#include <stdio.h>
#include <string.h>

#define MAXV    150001
#define MAXE    (MAXV*2)

typedef struct {
    int to, value, next;
} Edge_t;
Edge_t E[MAXE];
int Adj[MAXV], Queue[MAXV];
char Visit[MAXV];
int Size;

void Init()
{
    memset(Adj, -1, sizeof(Adj));
    memset(Visit, 0, sizeof(Visit));
    Size = 0;
}

void AddEdge(int from, int to, int value)
{
    E[Size].to = to;
    E[Size].value = value;
    E[Size].next = Adj[from];
    Adj[from] = Size++;
}

int BFS(int s)
{
    int head, tail;
    head = tail = 0;
    Visit[s] = 1;
    Queue[tail++] = s;
    int loop = 0;
    int edgeCnt = 0;
    while(head < tail) {
        int u = Queue[head++];
        for(int i = Adj[u]; ~i; i = E[i].next) {
            int v = E[i].to;
            ++edgeCnt;
            if(!Visit[v]) {
                if(loop > 0) {
                    return 1;
                }
                Visit[v] = 1;
                Queue[tail++] = v;
            }
        }
        ++loop;
    }
    if((long long)edgeCnt < (long long)tail * (tail - 1)) {
        return 1;
    }
    return 0;
}

int main()
{
    int n, m, a, b;
    Init();
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        AddEdge(a, b, 1);
        AddEdge(b, a, 1);
    }
    for(int i = 1; i <= n; ++i) {
        if(!Visit[i]) {
            if(BFS(i)) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
