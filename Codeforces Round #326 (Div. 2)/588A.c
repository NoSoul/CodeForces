#include <stdio.h>

int main()
{
    int N, i, Sum;
    int A[100000], P[100000];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &A[i], &P[i]);
    }
    for(i = 1; i < N; ++i) {
        if(P[i] > P[i - 1]) {
            P[i] = P[i - 1];
        }
    }
    Sum = 0;
    for(i = 0; i < N; ++i) {
        Sum += A[i] * P[i];
    }
    printf("%d\n", Sum);
    return 0;
}
