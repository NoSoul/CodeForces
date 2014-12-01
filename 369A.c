#include <stdio.h>

int main()
{
    int N, M, K, i, type, Cnt;
    scanf("%d %d %d", &N, &M, &K);
    for(Cnt = i = 0; i < N; ++i)
    {
        scanf("%d", &type);
        if(type == 1)
        {
            if(M)
            {
                --M;
            }
            else
            {
                ++Cnt;
            }
        }
        else
        {
            if(K)
            {
                --K;
            }
            else
            {
                if(M)
                {
                    --M;
                }
                else
                {
                    ++Cnt;
                }
            }
        }
    }
    printf("%d\n", Cnt);
    return 0;
}
