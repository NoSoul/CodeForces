#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    puts(((a == b || a + 1 == b || a == b + 1) && (a + b != 0)) ? "YES" : "NO");
    return 0;
}
