#include <stdio.h>

int main()
{
    int N,M,i;
    scanf("%d %d",&N,&M);
    printf("%d\n1 1\n",N+M-1);
    for(i=2; i<=N; ++i)
    {
        printf("%d 1\n",i);
    }
    for(i=2; i<=M; ++i)
    {
        printf("1 %d\n",i);
    }
}
