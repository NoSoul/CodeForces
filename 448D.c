#include <stdio.h>

long long GetLT(long long x, int N, int M)
{
    int i;
    long long ret = 0;
    for(i = 1; i <= N; ++i) {
        if((x - 1) / i > M) {
            ret += M;
        } else {
            ret += (x - 1) / i;
        }
    }
    return ret;
}

int main()
{
    int N, M;
    long long K, Left, Right, Mid;
    scanf("%d %d %I64d", &N, &M, &K);
    Left = 1;
    Right = (long long)N * M;
    while(Left < Right - 1) {
        Mid = (Left + Right) >> 1;
        if(GetLT(Mid, N, M) < K) {
            Left = Mid;
        } else {
            Right = Mid - 1;
        }
    }
    if(GetLT(Right, N, M) < K) {
        printf("%I64d\n", Right);
    } else {
        printf("%I64d\n", Left);
    }
    return 0;
}
