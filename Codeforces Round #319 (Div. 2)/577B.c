#include <stdio.h>

int A[1000];
char Dp[2][1000];

int main()
{
    int N, M, i, j, k, Num;
    scanf("%d %d", &N, &M);
    while(N--) {
        scanf("%d", &Num);
        Num %= M;
        ++A[Num];
    }
    if(A[0]) {
        puts("YES");
        return 0;
    }
    int idx = 1;
    for(i = 1; i < M; ++i) {
        if(A[i]) {
            idx ^= 1;
            for(j = 1; j <= A[i]; ++j) {
                for(k = 1; k < M; ++k) {
                    if(Dp[idx ^ 1][k]) {
                        int to = k + j * i;
                        to %= M;
                        Dp[idx][to] = 1;
                    }
                }
            }
            for(j = 1; j <= A[i]; ++j) {
                int to = j * i;
                to %= M;
                Dp[idx][to] = 1;
            }
            for(j = 0; j < M; ++j) {
                if(Dp[idx ^ 1][j]) {
                    Dp[idx][j] = 1;
                }
            }
            if(Dp[idx][0]) {
                break;
            }
        }
    }
    puts(Dp[idx][0] ? "YES" : "NO");
    return 0;
}
