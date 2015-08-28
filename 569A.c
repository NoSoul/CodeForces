#include <stdio.h>

int main()
{
    int T, S, q, Ans = 1;
    scanf("%d %d %d", &T, &S, &q);
    int p = 0;
    int Time = 0;
    while(1) {
        ++Time;
        ++p;
        if(S + Time * (q - 1) / q >= T) {
            break;
        }
        if(p * q >= q * S + Time * (q - 1)) {
            p = 0;
            ++Ans;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
