#include <stdio.h>

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        long long n;
        scanf("%I64d", &n);
        int ans = 0;
        while(n % 5 == 0) {
            n = n / 5 * 4;
            ++ans;
        }
        while(n % 3 == 0) {
            n = n / 3 * 2;
            ++ans;
        }
        while((n & 1) == 0) {
            n >>= 1;
            ++ans;
        }
        printf("%d\n", n == 1 ? ans : -1);
    }
    return 0;
}
