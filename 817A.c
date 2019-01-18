#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x2 -= x1;
    y2 -= y1;
    int x, y;
    scanf("%d %d", &x, &y);
    puts(x2 % x == 0 && y2 % y == 0 && (abs(x2 / x) & 1) == (abs(y2 / y) & 1) ? "YES" : "NO");
    return 0;
}
