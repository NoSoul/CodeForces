#include <stdio.h>

long long GCD(long long a, long long b)
{
    long long temp;
    while(b) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main()
{
    long long a, b, x, y;
    scanf("%I64d %I64d %I64d %I64d", &a, &b, &x, &y);
    long long factor = GCD(x, y);
    x /= factor;
    y /= factor;
    a /= x;
    b /= y;
    printf("%I64d\n", a < b ? a : b);
    return 0;
}
