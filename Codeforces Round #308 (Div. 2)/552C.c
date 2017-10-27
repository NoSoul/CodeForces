#include <stdio.h>

int A[40];

int main()
{
    int W, M, N, i;
    scanf("%d %d", &W, &M);
    if(W == 2) {
        puts("YES");
        return 0;
    }
    long long cur = 1;
    for(i = 1; i < 40; ++i) {
        cur *= W;
        if(cur > M) {
            break;
        }
    }
    N = i - 1;
    for(i = N; i >= 0; --i) {
        cur /= W;
        A[i] = M / cur;
        M -= A[i] * cur;
    }
    for(i = 0; i <= N; ++i) {
        if(A[i] <= 1) {
            continue;
        }
        if(A[i] == W) {
            ++A[i + 1];
            continue;
        }
        if(A[i] != W - 1) {
            puts("NO");
            return 0;
        }
        ++A[i + 1];
    }
    puts("YES");
    return 0;
}
