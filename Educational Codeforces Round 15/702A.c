#include <stdio.h>

int main()
{
    int N, Pre, Num, Ans = 0, Cur = 1;
    scanf("%d %d", &N, &Pre);
    for(int i = 1; i < N; ++i) {
        scanf("%d", &Num);
        if(Num > Pre) {
            ++Cur;
        } else {
            if(Cur > Ans) {
                Ans = Cur;
            }
            Cur = 1;
        }
        Pre = Num;
    }
    if(Cur > Ans) {
        Ans = Cur;
    }
    printf("%d\n", Ans);
    return 0;
}
