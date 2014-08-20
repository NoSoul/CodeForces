#include <stdio.h>

int main()
{
    int i,N,Min,Max,Minid,Maxid;
    int A[100];
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    for(Minid=0,Min=A[0],i=1; i<N; ++i)
    {
        if(Min>=A[i])
        {
            Min=A[i];
            Minid=i;
        }
    }
    for(Maxid=N-1,Max=A[N-1],i=N-2; i>=0; --i)
    {
        if(Max<=A[i])
        {
            Max=A[i];
            Maxid=i;
        }
    }
    if(Minid<Maxid)
    {
        printf("%d\n",N-Minid+Maxid-2);
    }
    else
    {
        printf("%d\n",N-Minid+Maxid-1);
    }
    return 0;
}
