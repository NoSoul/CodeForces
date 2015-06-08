#include <stdio.h>

typedef __int64 LL;

LL Cal(LL v, LL k)
{
    LL sum = v, b = k;
    while(v >= b) {
        sum += v / b;
        b *= k;
    }
    return sum;
}

int main()
{
    LL N, K, Left, Right, Mid;
    scanf("%I64d %I64d", &N, &K);
    Left = 1;
    Right = K * N;
    while(Right > Left) {
        Mid = (Left + Right) / 2;
        if(Cal(Mid, K) < N) {
            Left = Mid + 1;
        } else {
            Right = Mid;
        }
    }
    printf("%d\n", Left);
    return 0;
}
