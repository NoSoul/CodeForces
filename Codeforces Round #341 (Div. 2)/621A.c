#include <stdio.h>

int main()
{
    int N, i, Num, Min = 0x7fffffff, Cnt = 0;
    long long Sum = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        Sum += Num;
        if(Num & 1) {
            ++Cnt;
            if(Num < Min) {
                Min = Num;
            }
        }
    }
    if(Cnt & 1) {
        Sum -= Min;
    }
    printf("%I64d\n", Sum);
    return 0;
}
