#include <stdio.h>

int main()
{
    long long n;
    scanf("%I64d", &n);
    printf("%d\n", n & 1 ? 1 : 2);
    return 0;
}
