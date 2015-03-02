#include <stdio.h>

char B[100];
char G[100];

int main()
{
    int N, M, i, K, Num, Ans = 0;
    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    Ans += K;
    for(i = 0; i < K; ++i)
    {
        scanf("%d", &Num);
        B[Num] = 1;
    }
    scanf("%d", &K);
    Ans += K;
    for(i = 0; i < K; ++i)
    {
        scanf("%d", &Num);
        G[Num] = 1;
    }
    while(1)
    {
        int Cur = 0;
        for(i = 0; i < N * M; ++i)
        {
            if(B[i % N] || G[i % M])
            {
                if(!B[i % N])
                {
                    B[i % N] = 1;
                    ++Cur;
                    ++Ans;
                }
                if(!G[i % M])
                {
                    G[i % M] = 1;
                    ++Cur;
                    ++Ans;
                }
            }
        }
        if(Cur == 0)
        {
            break;
        }
    }
    puts(Ans == N + M ? "Yes" : "No");
    return 0;
}
