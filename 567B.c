#include <stdio.h>

char Flag[1000001];

int main()
{
    int N, i, Num;
    int Cur = 0, Ans = 0;
    char Str[2];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%s %d", Str, &Num);
        if(Str[0] == '+') {
            Flag[Num] = 1;
            if(Cur == Ans) {
                ++Ans;
            }
            ++Cur;
        } else {
            if(Flag[Num]) {
                --Cur;
            } else {
                ++Ans;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
