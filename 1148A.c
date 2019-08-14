#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%I64d\n", c * 2LL + (a < b ? a : b) * 2LL + (a != b));
    return 0;
}
