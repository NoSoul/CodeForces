#include <stdio.h>
#include <stdlib.h>

int A[100];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    printf("%d ", A[N - 1]);
    for(i = 1; i < N - 1; ++i) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[0]);
    return 0;
}
