#include <stdio.h>

int main()
{
    int N, Num, i, Cnt, Min, Max;
    scanf("%d %d", &N, &Min);
    for(Cnt = 0, Max = Min, i = 1; i < N; ++i) {
        scanf("%d", &Num);
        if(Num > Max) {
            ++Cnt;
            Max = Num;
        } else if(Num < Min) {
            ++Cnt;
            Min = Num;
        }
    }
    printf("%d\n", Cnt);
    return 0;
}
