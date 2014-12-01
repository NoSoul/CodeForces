#include <stdio.h>

int main()
{
    int N, K, i, j, Ans, One, Two;
    int A[100];
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(Ans = i = 0; i < K; ++i)
    {
        for(One = Two = 0, j = i; j < N; j += K)
        {
            if(A[j] == 1)
            {
                ++One;
            }
            else
            {
                ++Two;
            }
        }
        Ans += One < Two ? One : Two;
    }
    printf("%d\n", Ans);
    return 0;
}
