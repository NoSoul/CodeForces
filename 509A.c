#include <stdio.h>

int main()
{
    int A[10][10];
    int N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        A[0][i] = A[i][0] = 1;
    }
    for(i = 1; i < N; ++i) {
        for(j = 1; j < N; ++j) {
            A[i][j] = A[i - 1][j] + A[i][j - 1];
        }
    }
    printf("%d\n", A[N - 1][N - 1]);
    return 0;
}
