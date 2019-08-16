#include <stdio.h>

int main()
{
    long long x, y, z;
    scanf("%I64d %I64d %I64d", &x, &y, &z);
    printf("%I64d ", (x + y) / z);
    x %= z;
    y %= z;
    if(x + y >= z) {
        if(x >= y) {
            printf("%I64d\n", z - x);
        } else {
            printf("%I64d\n", z - y);
        }
    } else {
        puts("0");
    }
    return 0;
}
