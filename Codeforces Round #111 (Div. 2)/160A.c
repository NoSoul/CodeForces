#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a < *(int *)b ? 1 : -1;
}

int main()
{
    int N, i, sum, now;
    int A[100];
    scanf("%d", &N);
    for(sum = i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    qsort(A, N, sizeof(int), cmp);
    for(now = i = 0; i < N; ++i) {
        now += A[i];
        if(now > sum - now) {
            break;
        }
    }
    printf("%d\n", i + 1);
    return 0;
}
