#include <stdio.h>

int main()
{
    int N, i, Num, Max = 0;
    long long Sum = 0, Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        if(Num > Max) {
            Max = Num;
        }
        Sum += Num;
    }
    Sum = (long long)N * Max - Sum;
    Ans = Max;
    if(Ans > Sum) {
        int X = (Ans - Sum) / (N - 1);
        Ans += X;
        Sum += X * N;
        if(Sum < Ans) {
            Sum += N;
            ++Ans;
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
