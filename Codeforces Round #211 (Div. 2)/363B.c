#include <stdio.h>

#define MAXN	150001

int A[MAXN];

int main()
{
    int N, K, i, Sum, Min, index;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(Sum = i = 0; i < K; ++i) {
        Sum += A[i];
    }
    Min = Sum;
    index = 1;
    for(i = 1; i <= N - K; ++i) {
        Sum = Sum - A[i - 1] + A[i + K - 1];
        if(Sum < Min) {
            Min = Sum;
            index = i + 1;
        }
    }
    printf("%d\n", index);
    return 0;
}
