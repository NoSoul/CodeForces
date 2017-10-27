#include <stdio.h>

int main()
{
    int N, X, Ans = 0, i;
    scanf("%d %d", &N, &X);
    for(i = 1; i <= N ; ++i) {
        Ans += X % i == 0 && X / i <= N;
    }
    printf("%d\n", Ans);
    return 0;
}
