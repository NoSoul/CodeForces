#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV    (1<<16)
#define MAXINT  0x7f7f7f7f
typedef struct {
    int id;
    int d;
} Segment_t;
Segment_t Tree[MAXV << 1];
int D[MAXV], S[MAXV];
int AnsLen;
int AnsList[MAXV][2];

void Build(int N, int M)
{
    int i;
    for(i = M; i < N + M; ++i) {
        Tree[i].id = i - M;
        Tree[i].d = D[i - M];
    }
    for(i = N + M; i < (M << 1); ++i) {
        Tree[i].id = 0;
        Tree[i].d = MAXINT;
    }
    for(i = M - 1; i; --i) {
        Tree[i] = Tree[i << 1].d < Tree[(i << 1) + 1].d ?
                  Tree[i << 1] : Tree[(i << 1) + 1];
    }
}

void Update(int M, int x)
{
    x += M;
    if(--Tree[x].d <= 0) {
        Tree[x].d = MAXINT;
    }
    for(x >>= 1; x; x >>= 1) {
        Tree[x] = Tree[x << 1].d < Tree[(x << 1) + 1].d ?
                  Tree[x << 1] : Tree[(x << 1) + 1];
    }
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &D[i], &S[i]);
    }
    int M = ceil(log2(N));
    M = 1 << M;
    Build(N, M);
    for(i = 0; i < N - 1; ++i) {
        int u = Tree[1].id;
        int num = Tree[1].d;
        Update(M, u);
        if(num == 1) {
            int v = S[u];
            S[v] ^= u;
            AnsList[AnsLen][0] = u;
            AnsList[AnsLen++][1] = v;
            Update(M, v);
        }
    }
    printf("%d\n", AnsLen);
    for(i = 0; i < AnsLen; ++i) {
        printf("%d %d\n", AnsList[i][0], AnsList[i][1]);
    }
    return 0;
}
