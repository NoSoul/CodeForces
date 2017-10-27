#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d %d\n", (n / 7) * 2 + (n % 7 == 6), (n / 7) * 2 + (n % 7 > 0) + (n % 7 > 1));
    return 0;
}
