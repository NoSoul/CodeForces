#include <stdio.h>

int main()
{
    int table[] = {0, 1, 1, 0};
    int n;
    scanf("%d", &n);
    printf("%d\n", table[n & 3]);
    return 0;
}
