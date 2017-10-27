#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1 -= x2;
    y1 -= y2;
    x1 = abs(x1);
    y1 = abs(y1);
    printf("%d\n", x1 > y1 ? x1 : y1);
    return 0;
}
