#include <stdio.h>

int main()
{
    int N, i, Pre, Num, Cur = 1, Max = 0;
    scanf("%d %d", &N, &Pre);
    for(i = 1; i < N; ++i) {
        scanf("%d", &Num);
        if(Num >= Pre) {
            ++Cur;
        } else {
            if(Cur > Max) {
                Max = Cur;
            }
            Cur = 1;
        }
        Pre = Num;
    }
    if(Cur > Max) {
        Max = Cur;
    }
    printf("%d\n", Max);
    return 0;
}
