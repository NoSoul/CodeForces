#include <stdio.h>
#include <stdlib.h>

int A[50];

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int N, K, i;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    if(K > N) {
        printf("-1\n");
        return 0;
    }
    qsort(A, N, sizeof(int), cmp);
    printf("%d %d", A[K - 1], A[K - 1]);
    return 0;
}

