#include <stdio.h>

int main()
{
    int N,M,i;
    scanf("%d %d",&N,&M);
    M%=N*(N+1)/2;
    for(i=1; i<=N; ++i)
    {
        if(M>=i)
        {
            M-=i;
        }
        else
        {
            break;
        }
    }
    printf("%d\n",M);
    return 0;
}