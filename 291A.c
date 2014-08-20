#include <stdio.h>
#include <stdlib.h>

int A[1001];

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int N,i,Cnt,Res,Pre;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    qsort(A,N,sizeof(int),cmp);
    for(i=0; A[i]==0; ++i);
    for(Res=0,Pre=A[i],++i; i<N; ++i)
    {
        Cnt=1;
        while(A[i]==Pre&&i<N)
        {
            ++Cnt;
            ++i;
        }
        Pre=A[i];
        if(Cnt==1)
        {
            continue;
        }
        if(Cnt>2)
        {
            puts("-1");
            return 0;
        }
        ++Res;
    }
    printf("%d\n",Res);
    return 0;
}
