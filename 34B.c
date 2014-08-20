#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int N,M,i,Sum;
    int A[100];
    scanf("%d %d",&N,&M);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    qsort(A,N,sizeof(int),cmp);
    for(Sum=i=0; i<M&&A[i]<=0; ++i)
    {
        Sum+=A[i];
    }
    printf("%d\n",-Sum);
    return 0;
}
