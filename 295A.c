#include <stdio.h>

#define MAXN 100001

typedef long long LL_t;
typedef struct
{
    LL_t cnt;
} Segment;
Segment Tree[MAXN<<2];
typedef struct
{
    int l, r;
    LL_t add;
} Op_t;
Op_t His[MAXN];
int Data[MAXN];
int QueryX, QueryY;

void Build(int left, int right, int id)
{
    Tree[id].cnt = 0;
    if(left == right)
    {
        return;
    }
    int mid = (left+right)>>1;
    Build(left, mid, id<<1);
    Build(mid+1, right, (id<<1)+1);
}

void Update(int left, int right, LL_t value, int id)
{
    if(QueryY<left || QueryX>right)
    {
        return;
    }
    if(QueryX<=left && QueryY>=right)
    {
        Tree[id].cnt += value;
        return;
    }
    int mid = (left+right)>>1;
    Update(left, mid, value, id<<1);
    Update(mid+1, right, value, (id<<1)+1);
}

LL_t Query(int left, int right, LL_t pre, int id)
{
    if(QueryY<left || QueryX>right)
    {
        return 0;
    }
    if(QueryX<=left && QueryY>=right)
    {
        return Tree[id].cnt+pre;
    }
    int mid = (left+right)>>1;
    return Query(left, mid, pre+Tree[id].cnt, id<<1)+Query(mid+1, right, pre+Tree[id].cnt, (id<<1)+1);
}

int main()
{
    int N, M, K, i, num;
    LL_t Sum;
    scanf("%d %d %d",&N, &M, &K);
    for(i=1; i<=N; ++i)
    {
        scanf("%d",&Data[i]);
    }
    for(i=1; i<=M; ++i)
    {
        scanf("%d %d %I64d", &His[i].l, &His[i].r, &His[i].add);
    }
    Build(1, M, 1);
    while(K--)
    {
        scanf("%d %d", &QueryX, &QueryY);
        Update(1, M, 1, 1);
    }
    for(i=1; i<=M; ++i)
    {
        QueryX = QueryY = i;
        His[i].add *= Query(1, M, 0, 1);
    }
    Build(1, N, 1);
    for(i=1; i<=M; ++i)
    {
        QueryX = His[i].l;
        QueryY = His[i].r;
        Update(1, N, His[i].add, 1);
    }
    for(i=1; i<=N; ++i)
    {
        QueryX = QueryY = i;
        printf("%I64d ", (LL_t)Data[i]+Query(1, N, 0, 1));
    }
    puts("");
    return 0;
}
