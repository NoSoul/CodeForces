#include <stdio.h>

typedef __int64 LL_t;

int A[200001];
LL_t D[200001];

int main()
{
    int i, j, k, Cnt, N, K, Pre;
    LL_t Sum;
    scanf("%d %d", &N, &K);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    Cnt = D[1] = 0;
    Pre = A[1];
    for(i = k = 2, j = 1; i <= N; ++i) {
        Sum = (LL_t)Pre * (j - 1);
        if(D[k - 1] + Sum - (LL_t)(k - 1) * (N - Cnt - k)*A[i] < K) {
            printf("%d\n", i);
            ++Cnt;
        } else {
            D[k] = D[k - 1] + Sum;
            Pre = A[i];
            ++j;
            ++k;
        }
    }
    return 0;
}
