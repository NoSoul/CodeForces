#include <stdio.h>
#include <stdlib.h>

int A[100001];

int main()
{
    int i,N,Pre,Sum;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    Pre=A[0];
    Sum=N+A[0];
    for(i=1; i<N; ++i)
    {
        if(A[i]==Pre)
        {
            ++Sum;
        }
        else
        {
            Sum+=abs(Pre-A[i])+1;
        }
        Pre=A[i];
    }
    printf("%d\n",Sum);
    return 0;
}
