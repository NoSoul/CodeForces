#include <stdio.h>

int main()
{
    int N, i, Num, A = 0, B = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        A |= Num;
    }
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        B |= Num;
    }
    printf("%I64d\n", (long long)A + B);
    return 0;
}
