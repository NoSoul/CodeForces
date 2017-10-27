#include <stdio.h>

int main()
{
    long long a, b, ans = 1;
    scanf("%I64d %I64d", &a, &b);
    for(long long i = b; i > a; --i) {
        if(i % 10 == 0) {
            ans = 0;
            break;
        }
        ans *= i;
        ans %= 10;
    }
    printf("%I64d\n", ans);
    return 0;
}
