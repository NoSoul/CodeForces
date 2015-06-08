#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, K, i, j, Sum;
    int A[2000];
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(N), cmp);
    Sum = 0;
    for(i = N - 1; i >= 0; i -= K) {
        int pre = 1;
        for(j = (i - K + 1) < 0 ? 0 : i - K + 1; j <= i; ++j) {
            Sum += A[j] - pre;
            pre = A[j];
        }
        Sum += A[i] - 1;
    }
    printf("%d\n", Sum);
    return 0;
}
