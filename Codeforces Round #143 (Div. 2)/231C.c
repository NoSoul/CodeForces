#include <stdio.h>
#include <stdlib.h>

typedef __int64 LL;

int N, K;
int A[100001];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int i, j, X, Y;
    LL Sum;
    scanf("%d %d", &N, &K);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A + 1, N, sizeof(int), cmp);
    Sum = 0;
    X = j = 1;
    Y = A[1];
    for(i = 2; i <= N; ++i) {
        Sum += (long long)(A[i] - A[i - 1]) * (i - j);
        while(Sum > K) {
            Sum -= A[i] - A[j];
            ++j;
        }
        if(i - j + 1 > X) {
            X = i - j + 1;
            Y = A[i];
        }
    }
    printf("%d %d\n", X, Y);
    return 0;
}
