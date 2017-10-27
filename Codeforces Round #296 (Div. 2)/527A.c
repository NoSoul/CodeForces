#include <stdio.h>

int main()
{
    long long a, b;
    long long Ans = 0;
    scanf("%I64d %I64d", &a, &b);
    while(1) {
        if(a % b == 0) {
            Ans += a / b;
            break;
        }
        Ans += a / b;
        a %= b;
        long long c = a;
        a = b;
        b = c;
    }
    printf("%I64d\n", Ans);
    return 0;
}
