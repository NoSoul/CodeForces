#include <stdio.h>

int func(int a, int N)
{
    return a >= 1 && a <= N;
}

int main()
{
    int N, a, b, c, d, i;
    int cnt = 0;
    scanf("%d %d %d %d %d", &N, &a, &b, &c, &d);
    for(i = 1; i <= N; ++i) {
        if(func(b + i - c, N) && func(a + i - d, N) && func(a + b + i - c - d, N)) {
            ++cnt;
        }
    }
    printf("%I64d\n", (long long)N * cnt);
    return 0;
}
