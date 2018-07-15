#include <stdio.h>

int main()
{
    long long n;
    scanf("%I64d", &n);
    if(n == 0) {
        puts("0");
    } else {
        ++n;
        if(n & 1) {
            printf("%I64d\n", n);
        } else {
            printf("%I64d\n", n / 2);
        }
    }
    return 0;
}
