#include <stdio.h>

int main()
{
    int N, K, i, j, Ans;
    int A[100000];
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    if(K > N) {
        printf("%d\n", A[N - 1]);
        return 0;
    }
    for(i = N - K - 1, j = N - K; i >= 0; --i, ++j) {
        A[j] += A[i];
    }
    Ans = A[N - K];
    for(i = N - K; i < N; ++i) {
        if(Ans < A[i]) {
            Ans = A[i];
        }
    }
    printf("%d\n", Ans);
    return 0;
}
