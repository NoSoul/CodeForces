#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, i;
    int A[100];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", & A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    for(i = 0; i < N; ++i) {
        printf("%d ", A[i]);
    }
    return 0;
}
