#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int N,M,i,Min,Now;
    int A[50];
    scanf("%d %d",&N,&M);
    for(i=0; i<M; ++i)
    {
        scanf("%d",&A[i]);
    }
    qsort(A,M,sizeof(int),cmp);
    Min=0x7fffffff;
    for(i=0; i+N-1<M; ++i)
    {
        Now=A[i+N-1]-A[i];
        if(Now<Min)
        {
            Min=Now;
        }
    }
    printf("%d\n",Min);
    return 0;
}
