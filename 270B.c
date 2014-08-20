#include <stdio.h>

int A[100000];

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    for(i=N-1; A[i]>A[i-1]&&i>0; --i);
    printf("%d\n",i);
    return 0;
}

