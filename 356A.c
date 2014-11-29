#include <stdio.h>

#define MAXN    300001

typedef struct
{
    int conquered;
} Node_t;
Node_t Tree[MAXN<<2];
int RangeX, RangeY;

void Build(int left, int right, int id)
{
    if(left == right)
    {
        Tree[id].conquered = 0;
        return;
    }
    int mid = (left+right)>>1;
    Build(left, mid, id<<1);
    Build(mid+1, right, (id<<1)|1);
}

void Update(int left, int right, int value, int id)
{
    if(RangeX>right || RangeY<left)
    {
        return;
    }
    if(Tree[id].conquered)
    {
        return;
    }
    if(RangeX<=left && RangeY>=right)
    {
        if(Tree[id].conquered == 0)
        {
            Tree[id].conquered = value;
        }
        return;
    }
    int mid = (left+right)>>1;
    Update(left, mid, value, id<<1);
    Update(mid+1, right, value, (id<<1)|1);
}

int Query(int left, int right, int pre, int id)
{
    if(RangeX>right || RangeY<left)
    {
        return 0;
    }
    if(left==RangeX && RangeY==right)
    {
        return Tree[id].conquered?Tree[id].conquered:pre;
    }
    int mid = (left+right)>>1;
    return Query(left, mid, Tree[id].conquered?Tree[id].conquered:pre, id<<1)
           + Query(mid+1, right, Tree[id].conquered?Tree[id].conquered:pre,
                   (id<<1)|1);
}

int main()
{
    int N, M, i;
    int l, r, x;
    scanf("%d %d", &N, &M);
    Build(1, N, 1);
    while(M--)
    {
        scanf("%d %d %d", &l, &r, &x);
        RangeX = l;
        RangeY = x-1;
        Update(1, N, x, 1);
        RangeX = x+1;
        RangeY = r;
        Update(1, N, x, 1);
    }
    for(i=1; i<=N; ++i)
    {
        RangeX = i;
        RangeY = i;
        printf("%d ", Query(1, N, 0, 1));
    }
    puts("");
    return 0;
}
