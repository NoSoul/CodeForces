#include <stdio.h>

int N;
int A[101],B[101];

int Judge()
{
    int i;
    for(i=1; i<N; ++i)
    {
        if(B[i]&1)
        {
            break;
        }
    }
    if(i==N)
    {
        return 1;
    }
    for(i=1; i<N; ++i)
    {
        if(!(B[i]&1))
        {
            break;
        }
    }
    return i==N?1:0;
}

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for(i=1; i<=N; ++i)
    {
        scanf("%d",&A[i]);
    }
    for(i=1; i<=N; ++i)
    {
        for(j=k=1; j<=N; ++j)
        {
            if(j!=i)
            {
                B[k++]=A[j];
            }
        }
        if(Judge())
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
