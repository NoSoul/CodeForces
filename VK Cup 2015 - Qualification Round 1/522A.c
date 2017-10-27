#include <stdio.h>
#include <string.h>

#define MAXV    401
#define MAXE    201

char Name[MAXV][25];
int Num;

typedef struct {
    int to;
    int next;
} Edge_t;
Edge_t E[MAXE];
int Adj[MAXV];
int Size;
char Visit[MAXV];
int Queue[MAXV];

int GetIdx(char *str)
{
    int i;
    for(i = 0; str[i]; ++i) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
    }
    for(i = 0; i < Num; ++i) {
        if(strcmp(str, Name[i]) == 0) {
            return i;
        }
    }
    memcpy(Name[Num++], str, strlen(str));
    return Num - 1;
}

void Add(int u, int v)
{
    E[Size].to = v;
    E[Size].next = Adj[u];
    Adj[u] = Size++;
}

int BFS(int idx)
{
    memset(Visit, 0, sizeof(Visit));
    Visit[idx] = 1;
    Queue[0] = idx;
    int Head, Tail, i;
    Head = 0;
    Tail = 1;
    while(Head < Tail) {
        for(i = Adj[Queue[Head]]; ~i; i = E[i].next) {
            int j = E[i].to;
            if(!Visit[j]) {
                Visit[j] = 1;
                Queue[Tail++] = j;
            }
        }
        ++Head;
    }
    return Tail;
}

int main()
{
    int N, i, Max, Cur;
    char Str[25];
    scanf("%d", &N);
    memset(Adj, -1, sizeof(Adj));
    for(i = 0; i < N; ++i) {
        int u, v;
        scanf("%s", Str);
        u = GetIdx(Str);
        scanf("%*s %s", Str);
        v = GetIdx(Str);
        Add(u, v);
    }
    for(i = Max = 0; i < Num; ++i) {
        Cur = BFS(i);
        if(Cur > Max) {
            Max = Cur;
        }
    }
    printf("%d\n", Max);
    return 0;
}
