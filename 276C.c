#include <stdio.h>
#include <stdlib.h>

#define MAXN 200001

typedef long long LL;
typedef struct
{
    int cnt;
} Segment;
Segment Tree[MAXN<<2];
int Data[MAXN],Cnt[MAXN];
int X,Y;

void Build(int left,int right,int id)
{
    int mid;
    Tree[id].cnt=0;
    if(left==right)
    {
        return;
    }
    mid=(left+right)>>1;
    Build(left,mid,id<<1);
    Build(mid+1,right,(id<<1)+1);
}

void Update(int left,int right,int value,int id)
{
    int mid;
    if(Y<left||X>right)
    {
        return;
    }
    if(X<=left&&Y>=right)
    {
        Tree[id].cnt+=value;
        return;
    }
    mid=(left+right)>>1;
    Update(left,mid,value,id<<1);
    Update(mid+1,right,value,(id<<1)+1);
}

int Query(int left,int right,int pre,int id)
{
    int mid;
    if(Y<left||X>right)
    {
        return 0;
    }
    if(X<=left&&Y>=right)
    {
        return Tree[id].cnt+pre;
    }
    mid=(left+right)>>1;
    return Query(left,mid,pre+Tree[id].cnt,id<<1)+Query(mid+1,right,pre+Tree[id].cnt,(id<<1)+1);
}

int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int N,Q,i;
    LL Sum;
    scanf("%d %d",&N,&Q);
    for(i=1; i<=N; ++i)
    {
        scanf("%d",&Data[i]);
    }
    qsort(Data+1,N,sizeof(int),cmp);
    Build(1,N,1);
    while(Q--)
    {
        scanf("%d %d",&X,&Y);
        Update(1,N,1,1);
    }
    for(i=1; i<=N; ++i)
    {
        X=Y=i;
        Cnt[i]=Query(1,N,0,1);
    }
    qsort(Cnt+1,N,sizeof(int),cmp);
    Sum=0;
    for(i=1; i<=N; ++i)
    {
        Sum+=(LL)Cnt[i]*Data[i];
    }
    printf("%I64d\n",Sum);
    return 0;
}
