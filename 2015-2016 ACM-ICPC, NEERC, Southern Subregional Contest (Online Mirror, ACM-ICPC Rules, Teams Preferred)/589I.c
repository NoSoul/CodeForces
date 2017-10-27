#include <stdio.h>

unsigned char A[100];

int main()
{
    int N, K, i, M, Num, Ans = 0;
    scanf("%d %d", &N, &K);
    M = N / K;
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        ++A[Num - 1];
    }
    for(i = 0; i < K; ++i) {
        if(A[i] > M) {
            Ans += A[i] - M;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
