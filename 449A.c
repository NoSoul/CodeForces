#include <stdio.h>

int main()
{
    int N, M, K, temp;
    long long Ans;
    scanf("%d %d %d", &N, &M, &K);
    if(K > (N + M - 2)) {
        puts("-1");
    } else {
        if(K <= N - 1) {
            Ans = (long long)(N / (K + 1)) * M;
        } else {
            Ans = M / (K - N + 2);
        }

        if(K <= M - 1) {
            if((long long)(M / (K + 1))*N > Ans) {
                Ans = (long long)(M / (K + 1)) * N;
            }
        } else {
            if(N / (K - M + 2) > Ans) {
                Ans = N / (K - M + 2);
            }
        }
        printf("%I64d\n", Ans);
    }
    return 0;
}
