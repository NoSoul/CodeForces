#include <stdio.h>
#include <stdlib.h>

int A[51];
int Hash[51];

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}


int main()
{
    int N, M, K, i, Sum;
    scanf("%d %d %d", &N, &M, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        --A[i];
    }
    qsort(A, N, sizeof(int), cmp);
    Sum = K;
    if(Sum >= M) {
        printf("0\n");
        return 0;
    }
    for(i = 0; A[i] && i < N; ++i) {
        Sum += A[i];
        if(Sum >= M) {
            break;
        }
    }
    if(Sum >= M) {
        printf("%d\n", i + 1);
    } else {
        printf("-1\n");
    }
    return 0;
}
