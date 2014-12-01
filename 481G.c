#include <stdio.h>

#define MAXN    200000

int A[MAXN];

int main()
{
    int N, K, i, OriginMin, Add, j, Ans;
    scanf("%d %d", &N, &K);
    OriginMin = 0;
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
        if(A[i] < OriginMin)
        {
            OriginMin = A[i];
        }
    }
    Add = 0;
    for(i = N - 1; i > N - K; --i)
    {
        Add += A[i];
    }
    Ans = 0;
    for(i = N - K; i >= 0; --i)
    {
        if(A[i] + Add > -1)
        {
            int remain = A[i] + Add + 1;
            for(j = i; j < i + K; ++j)
            {
                if(remain > A[j] - OriginMin)
                {
                    remain -= A[j] - OriginMin;
                    if(j != i)
                    {
                        Add -= A[j] - OriginMin;
                    }
                    Ans += A[j] - OriginMin;
                    A[j] = OriginMin;
                }
                else
                {
                    if(j != i)
                    {
                        Add -= remain;
                    }
                    Ans += remain;
                    A[j] -= remain;
                    break;
                }
            }
        }
        Add -= A[i + K - 1];
        Add += A[i];
    }
    printf("%d\n", Ans);
    for(i = 0; i < N; ++i)
    {
        printf("%d ", A[i]);
    }
    puts("");
    return 0;
}
