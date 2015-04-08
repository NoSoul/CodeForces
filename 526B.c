#include <stdio.h>

int main()
{
    int N, M, i, j, Ans = 0;
    int A[2048];
    scanf("%d", &N);
    M = 1 << (N + 1);
    for(i = 2; i < M; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(i = N; i > 0; --i)
    {
        for(j = (1 << i); j < (1 << (i + 1)); j += 2)
        {
            int Cur = A[j] > A[j + 1] ? A[j] : A[j + 1];
            Ans += Cur + Cur - A[j] - A[j + 1];
            A[j / 2] += Cur;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
