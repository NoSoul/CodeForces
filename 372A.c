#include <stdio.h>
#include <stdlib.h>

#define MAXN	500001

int A[MAXN];
char Hash[MAXN];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, i, j, Ans;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    j = N / 2 - 1;
    for(i = N - 1; i >= N / 2; --i) {
        for(; j >= 0; --j) {
            if(A[i] >= A[j] * 2) {
                Hash[i] = 2;
                Hash[j] = 1;
                --j;
                break;
            }
        }
    }
    Ans = 0;
    for(i = 0; i < N; ++i) {
        Ans += Hash[i] != 1;
    }
    printf("%d\n", Ans);
    return 0;
}
