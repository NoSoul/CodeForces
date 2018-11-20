#include <stdio.h>
#include <string.h>

#define MAXN    100001

typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t E[MAXN << 1];
int Adj[MAXN];
int Size;

char Types[MAXN];
char Visited[MAXN];
int Data[MAXN];
int Hash[MAXN];
int Degree[MAXN];

void Init(int N)
{
    int i;
    for(Size = i = 0; i <= N; ++i) {
        Adj[i] = -1;
    }
}

void Add_Edge(int u, int v)
{
    E[Size].to = v;
    E[Size].next = Adj[u];
    Adj[u] = Size++;
    return;
}

int FindPath(int u, int mode)
{
    int i, cnt = 1;
    if(mode == 1) {
        printf("%d ", u);
    }
    for(i = Adj[u]; ~i; i = Adj[E[i].to]) {
        ++cnt;
        if(mode == 1) {
            printf("%d ", E[i].to);
        }
        if(Types[E[i].to] == 1) {
            return cnt;
        }
    }
    return -1;
}

int main()
{
    int N, i, Max, Now, Maxu;
    scanf("%d", &N);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &Types[i]);
    }
    for(i = 1; i <= N; ++i) {
        scanf("%d", &Data[i]);
        ++Hash[Data[i]];
    }
    Init(N);
    for(i = 1; i <= N; ++i) {
        if(Data[i] == 0 || Hash[i] > 1 || Hash[Data[i]] > 1) {
            continue;
        }
        Add_Edge(Data[i], i);
        ++Degree[i];
        Visited[Data[i]] = 1;
        Visited[i] = 1;
    }
    Max = 1;
    for(i = 1; i <= N; ++i) {
        if(Degree[i] == 0 && Visited[i] == 1) {
            Now = FindPath(i, 0);
            if(Now > Max) {
                Max = Now;
                Maxu = i;
            }
        }
    }
    printf("%d\n", Max);
    if(Max == 1) {
        for(i = 1; i <= N; ++i) {
            if(Types[i] == 1) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    FindPath(Maxu, 1);
    return 0;
}
