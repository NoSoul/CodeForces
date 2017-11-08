#include <stdio.h>

int main()
{
    int n, ans = 0, d = 1;
    scanf("%d", &n);
    if(n < 10) {
        puts("1");
    } else {
        while(n >= 10) {
            if(n % 10) {
                ans += (10 - n % 10) * d;
                n = n / 10 + 1;
            } else {
                n /= 10;
            }
            d *= 10;
        }
        if(ans == 0) {
            ans = d;
        }
        printf("%d\n", ans);
    }
    return 0;
}
