#include <stdio.h>

int main()
{
    int N, i, j, k, Ans = 0x7fffffff;
    int A[2][50], B[50];
    scanf("%d", &N);
    for(j = 0; j < 2; ++j) {
        for(i = 0; i < N - 1; ++i) {
            scanf("%d", &A[j][i]);
        }
    }
    for(i = 0; i < N; ++i) {
        scanf("%d", &B[i]);
    }
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            if(i != j) {
                int cur = 0;
                for(k = i; k < N - 1; ++k) {
                    cur += A[1][k];
                }
                cur += B[i];
                for(k = 0; k < i; ++k) {
                    cur += A[0][k];
                }
                for(k = 0; k < j; ++k) {
                    cur += A[0][k];
                }
                cur += B[j];
                for(k = j; k < N - 1; ++k) {
                    cur += A[1][k];
                }
                if(cur < Ans) {
                    Ans = cur;
                }
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
