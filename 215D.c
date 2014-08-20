#include <stdio.h>

#define LL __int64
#define MAXN 100001

typedef struct
{
    LL t,T,x,cost;
} Regions;
Regions R[MAXN];

LL Sum,A,B;

int main()
{
    int N,M,i;
    LL d,num;
    scanf("%d %d",&N,&M);
    for(Sum=i=0; i<N; ++i)
    {
        scanf("%I64d %I64d %I64d %I64d",&R[i].t,&R[i].T,&R[i].x,&R[i].cost);
        d=R[i].T-R[i].t;
        if(d<=0)
        {
            Sum+=M*R[i].x+R[i].cost;
            continue;
        }
        num=M/d;
        if(M%d!=0)
        {
            ++num;
        }
        A=num*R[i].cost;
        B=M*R[i].x;
        if(A>B+R[i].cost)
        {
            Sum+=B+R[i].cost;
        }
        else
        {
            Sum+=A;
        }
    }
    printf("%I64d\n",Sum);
    return 0;
}
