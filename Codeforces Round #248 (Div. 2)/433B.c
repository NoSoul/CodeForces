#include <stdio.h>
#include <stdlib.h>

#define MAXN    100001

int A[MAXN];
int B[MAXN];
long long SumA[MAXN];
long long SumB[MAXN];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, i, M, type, l, r;
    scanf("%d", &N);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        B[i] = A[i];
    }
    qsort(B + 1, N, sizeof(int), cmp);
    for(i = 1; i <= N; ++i) {
        SumA[i] = SumA[i - 1] + A[i];
        SumB[i] = SumB[i - 1] + B[i];
    }
    scanf("%d", &M);
    while(M--) {
        scanf("%d %d %d", &type, &l, &r);
        if(type == 1) {
            printf("%I64d\n", SumA[r] - SumA[l - 1]);
        } else {
            printf("%I64d\n", SumB[r] - SumB[l - 1]);
        }
    }
    return 0;
}
