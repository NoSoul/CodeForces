#include <stdio.h>

typedef struct
{
    int y, n;
} Film;
Film F[100];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int M, K, N, D, Num, i, j, k, yes, no, zero, Max;
    int A[100];
    while(scanf("%d %d", &M, &K) != EOF)
    {
        for(i = 0; i < K; ++i)
        {
            scanf("%d", &A[i]);
        }
        scanf("%d", &N);
        for(Max = -1, i = 0; i < N; ++i)
        {
            scanf("%*s %d", &D);
            yes = no = zero = 0;
            for(k = 0; k < D; ++k)
            {
                scanf("%d", &Num);
                if(Num == 0)
                {
                    ++zero;
                    continue;
                }
                for(j = 0; j < K; ++j)
                {
                    if(Num == A[j])
                    {
                        ++yes;
                        break;
                    }
                }
                if(j == K)
                {
                    ++no;
                }
            }
            if(zero > M - K - no)
            {
                yes += zero - M + K + no;
                zero = M - K - no;
            }
            if(zero > K - yes)
            {
                zero = K - yes;
            }
            F[i].y = yes;
            F[i].n = zero;
            if(yes > Max)
            {
                Max = yes;
            }
        }
        for(i = 0; i < N; ++i)
        {
            if(F[i].y == Max)
            {
                for(j = 0; j < N; ++j)
                {
                    if(i != j)
                    {
                        if(F[j].y + F[j].n > Max)
                        {
                            printf("2\n");
                            break;
                        }
                    }
                }
                if(j == N)
                {
                    printf("0\n");
                }
            }
            else if(F[i].y + F[i].n < Max)
            {
                printf("1\n");
            }
            else
            {
                printf("2\n");
            }
        }
    }
    return 0;
}
