#include <stdio.h>
#include <stdlib.h>

#define MAXN    1001

typedef struct {
    int v, next;
} Edge_t;
Edge_t E[MAXN], _E[MAXN];
int Adj[MAXN], _Adj[MAXN];

int A[MAXN];
int Set[MAXN];
int Size, _Size, Cnt, Now;
char Hash[MAXN];

typedef struct {
    int value, num;
} BSet_t;
BSet_t BSet[MAXN];
int CntB;
int c1[MAXN], c2[MAXN];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void Init(int N)
{
    int i;
    for(i = Size = _Size = 0; i <= N; ++i) {
        Adj[i] = _Adj[i] = -1;
    }
}

void Add_Edge(int u, int v)
{
    E[Size].v = v;
    Adj[u] = Size++;
}

void _Add_Edge(int u, int v)
{
    _E[_Size].v = v;
    _Adj[u] = _Size++;
}

void Clear(int id, int mode)
{
    int i, cnt = 1;
    Hash[id] = 0;
    for(i = Adj[id]; ~i; i = Adj[E[i].v]) {
        Hash[E[i].v] = 0;
        ++cnt;
    }
    if(mode == 0) {
        Now = cnt;
    }
    for(i = _Adj[id]; ~i; i = _Adj[_E[i].v]) {
        Hash[_E[i].v] = 0;
        ++cnt;
    }
    Set[Cnt++] = cnt;
}

int main()
{
    int N, X, i, j, k, Sum;
    scanf("%d %d", &N, &X);
    Init(N);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        if(A[i] != 0) {
            Add_Edge(i, A[i]);
            _Add_Edge(A[i], i);
            Hash[i] = Hash[A[i]] = 1;
        }
    }
    Clear(X, 0);
    if(A[X] == 0) {
        Now = 1;
    }
    for(i = 1; i <= N; ++i) {
        if(Hash[i]) {
            Clear(i, 1);
        }
    }
    for(Sum = i = 0; i < Cnt; ++i) {
        Sum += Set[i];
    }
    Sum = N - Sum;
    while(Sum--) {
        Set[Cnt++] = 1;
    }
    qsort(Set + 1, Cnt - 1, sizeof(int), cmp);
    if(Cnt > 1) {
        BSet[CntB].value = Set[1];
        BSet[CntB].num = 1;
        CntB = 1;
        for(i = 2; i < Cnt; ++i) {
            if(Set[i] == BSet[CntB - 1].value) {
                ++BSet[CntB - 1].num;
            } else {
                BSet[CntB].value = Set[i];
                BSet[CntB].num = 1;
                ++CntB;
            }
        }
        for(i = 0; i <= BSet[0].num * BSet[0].value; i += BSet[0].value) {
            c1[i] = 1;
        }
        for(i = 1; i < CntB; ++i) {
            for(j = 0; j <= N; ++j) {
                if(c1[j]) {
                    for(k = 0; k <= BSet[i].num * BSet[i].value; k += BSet[i].value) {
                        c2[k + j] += c1[j];
                    }
                }
            }
            for(j = 0; j <= N; ++j) {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        for(i = 0; i <= N; ++i) {
            if(c1[i]) {
                printf("%d\n", i + Now);
            }
        }
    } else {
        printf("%d\n", Now);
    }
    return 0;
}
