#include <stdio.h>

int main()
{
    int N, K, Ans = 0;
    int A[500];
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(int i = 1; i < N; ++i) {
        int cur = A[i] + A[i - 1];
        if(K - cur > 0) {
            Ans += K - cur;
            A[i] += K - cur;
        }
    }
    printf("%d\n", Ans);
    for(int i = 0; i < N; ++i) {
        printf("%d ", A[i]);
    }
    puts("");
    return 0;
}
