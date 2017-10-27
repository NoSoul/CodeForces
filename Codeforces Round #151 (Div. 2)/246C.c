#include <stdio.h>
#include <stdlib.h>

int A[50];

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int N, i, K, Now, j;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    Now = 0;
    while(K) {
        for(i = Now; K && i < N; ++i) {
            if(K) {
                printf("%d ", Now + 1);
                for(j = 0; j < Now; ++j) {
                    printf("%d ", A[j]);
                }
                printf("%d\n", A[i]);
                K--;
            }
        }
        Now++;
    }
    return 0;
}
