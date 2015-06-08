#include <stdio.h>

int main()
{
    int N, i, Sum, Num, Cnt;
    scanf("%d", &N);
    for(Sum = i = 0; i < N; ++i) {
        scanf("%d", &Num);
        Sum += Num;
    }
    for(Cnt = 0, i = 1; i < 6; ++i) {
        if((Sum + i) % (N + 1) != 1) {
            ++Cnt;
        }
    }
    printf("%d\n", Cnt);
    return 0;
}

