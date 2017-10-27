#include <stdio.h>

int main()
{
    int N, K, M, i, j;
    int A[500][500];
    scanf("%d %d", &N, &K);
    --K;
    M = N * N;
    for(i = 0; i < N; ++i) {
        for(j = N - 1; j >= K; --j) {
            A[i][j] = M;
            --M;
        }
    }
    for(i = 0; i < N; ++i) {
        for(j = K - 1; j >= 0; --j) {
            A[i][j] = M;
            --M;
        }
    }
    int Sum = 0;
    for(i = 0; i < N; ++i) {
        Sum += A[i][K];
    }
    printf("%d\n", Sum);
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            printf("%d ", A[i][j]);
        }
        puts("");
    }
    return 0;
}
