#include <stdio.h>

int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    if(3*N<=K)
    {
        puts("0");
        return 0;
    }
    printf("%d\n",3*N-K);
    return 0;
}
