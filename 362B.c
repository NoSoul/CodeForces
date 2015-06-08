#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int i, N, M;
    int A[3000];
    scanf("%d %d", &N, &M);
    for(i = 0; i < M; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, M, sizeof(int), cmp);
    if(A[0] == 1 || A[M - 1] == N) {
        puts("NO");
        return 0;
    }
    for(i = 0; i < M - 2; ++i) {
        if(A[i + 1] == A[i] + 1 && A[i + 2] == A[i] + 2) {
            puts("NO");
            return 0;
        }
    }
    puts("YES\n");
    return 0;
}
