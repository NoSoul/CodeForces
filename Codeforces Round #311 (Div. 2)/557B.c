#include <stdio.h>
#include <stdlib.h>

#define eps 1e-8

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, W, i;
    int A[200000];
    scanf("%d %d", &N, &W);
    for(i = 0; i < N << 1; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, N << 1, sizeof(A[i]), cmp);
    int max = A[N] < 2 * A[0] ? A[N] : 2 * A[0];
    if((long long)3 * max * N < 2 * W) {
        printf("%.1lf\n", max * N * 1.5);
    } else {
        printf("%d\n", W);
    }
    return 0;
}
