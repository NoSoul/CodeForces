#include <stdio.h>

int x, y;
char left;

void Fun(int M)
{
    printf(" %d %d", x + 1, y + 1);
    if(left)
    {
        if(y == 0)
        {
            ++x;
            left ^= 1;
        }
        else
        {
            --y;
        }
    }
    else
    {
        if(y == M - 1)
        {
            ++x;
            left ^= 1;
        }
        else
        {
            ++y;
        }
    }
}

int main()
{
    int N, M, K, i, j;
    scanf("%d %d %d", &N, &M, &K);
    int R = N * M % K;
    int Len = N * M / K + R;
    printf("%d", Len);
    for(i = 0; i < Len; ++i)
    {
        Fun(M);
    }
    puts("");
    Len = N * M / K;
    for(j = 1; j < K; ++j)
    {
        printf("%d", Len);
        for(i = 0; i < Len; ++i)
        {
            Fun(M);
        }
        puts("");
        Len = N * M / K;
    }
    return 0;
}
