#include <stdio.h>

int main()
{
    int N,K,i,Sum,Min;
    int A[100000];
    scanf("%d %d",&N,&K);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    for(i=0; K&&A[i]<0&&i<N; ++i)
    {
        A[i]*=-1;
        --K;
    }
    for(Min=A[0],Sum=i=0; i<N; ++i)
    {
        Sum+=A[i];
        if(A[i]<Min)
        {
            Min=A[i];
        }
    }
    if(K%2)
    {
        Sum-=2*Min;
    }
    printf("%d\n",Sum);
    return 0;
}
