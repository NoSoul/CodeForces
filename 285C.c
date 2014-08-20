#include <stdio.h>
#include <stdlib.h>

typedef long long LL;
int A[300001];

int cmp(const void  *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int N,i;
    LL Sum;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    qsort(A,N,sizeof(int),cmp);
    for(i=0; i<N; ++i)
    {
        Sum+=abs(A[i]-i-1);
    }
    printf("%I64d\n",Sum);
    return 0;
}
