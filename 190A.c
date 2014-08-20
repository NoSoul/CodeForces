#include <stdio.h>

int main()
{
    int N,M,Min,Max;
    scanf("%d %d",&N,&M);
    if(N==0&&M)
    {
        puts("Impossible");
        return 0;
    }
    Min=N;
    if(M>N)
    {
        Min+=M-N;
    }
    Max=N;
    if(M>0)
    {
        Max+=M-1;
    }
    printf("%d %d\n",Min,Max);
    return 0;
}
