#include <stdio.h>
#include <stdlib.h>

#define LL __int64

typedef struct
{
    int index,num;
    LL  cnt;
} Cho;
Cho C[50];
int A[50];

int cmp1(const void *a,const void *b)
{
    return (*(Cho *)a).index>(*(Cho *)b).index?1:-1;
}

int cmp2(const void *a,const void *b)
{
    return (*(Cho *)a).num<(*(Cho *)b).num?1:-1;
}

int main()
{
    int i,N,j,k;
    LL Sum;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    for(i=0; i<5; ++i)
    {
        scanf("%d",&C[i].num);
        C[i].index=i;
        C[i].cnt=0;
    }
    qsort(C,5,sizeof(Cho),cmp2);
    for(Sum=i=0; i<N; ++i)
    {
        Sum+=A[i];
        while(Sum>=C[4].num)
        {
            for(j=0; j<5; ++j)
            {
                if(Sum>=C[j].num)
                {
                    k=Sum/C[j].num;
                    C[j].cnt+=k;
                    Sum-=k*C[j].num;
                    break;
                }
            }
        }
    }
    qsort(C,5,sizeof(Cho),cmp1);
    for(i=0; i<4; ++i)
    {
        printf("%I64d ",C[i].cnt);
    }
    printf("%I64d\n%I64d\n",C[i].cnt,Sum);
    return 0;
}
