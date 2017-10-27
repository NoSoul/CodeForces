#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int N, M, i, Ans = 0;
    int A[100];
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    for(i = 0; i < N; ++i) {
        if(M > 0) {
            M -= A[i];
            ++Ans;
        }
        if(M <= 0) {
            break;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
