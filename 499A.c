#include <stdio.h>

int main()
{
    int N, X, Cur, L, R, Sum;
    scanf("%d %d", &N, &X);
    Cur = 1;
    Sum = 0;
    while(N--)
    {
        scanf("%d %d", &L, &R);
        int num = (L - Cur) / X;
        Cur += num * X;
        Sum += R - Cur + 1;
        Cur = R + 1;
    }
    printf("%d\n", Sum);
    return 0;
}
