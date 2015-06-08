#include <stdio.h>

int Solve(int K, int L)
{
    int cnt = 0, j;
    __int64 a;
    while(L != 1) {
        a = K;
        j = 1;
        while(L >= (a * a)) {
            a *= a;
            j *= 2;
        }
        cnt += (a == K) ? 1 : j;
        if(L % a != 0) {
            return -1;
        }
        L /= a;
    }
    return cnt - 1;
}

int main()
{
    int K, L;
    while(scanf("%d %d", &K, &L) != EOF) {
        if(L % K != 0) {
            puts("NO");
            continue;
        }
        L = Solve(K, L);
        if(L == -1) {
            puts("NO");
            continue;
        }
        puts("YES");
        printf("%d\n", L);
    }
    return 0;
}
