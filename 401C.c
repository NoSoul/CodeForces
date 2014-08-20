#include <stdio.h>

int main()
{
    int N, M, i;
    scanf("%d %d", &N, &M);
    if((M>(N+1)*2) || (M<N-1))
    {
        puts("-1");
    }
    else
    {
        if(N > M)
        {
            printf("0");
            --N;
        }
        int temp = M-N;
        if(temp > N)
        {
            temp = N;
        }
        for(i=0; i<temp; ++i)
        {
            printf("110");
        }
        M -= temp*2;
        N -= temp;
        for(i=0; i<N; ++i)
        {
            printf("10");
        }
        M -= N;
        for(i=0; i<M; ++i)
        {
            printf("1");
        }
    }
    return 0;
}
