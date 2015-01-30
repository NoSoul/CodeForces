#include <stdio.h>
#include <math.h>

int main()
{
    int r, x, y, x1, y1;
    scanf("%d %d %d %d %d", &r, &x, &y, &x1, &y1);
    double dis = sqrt(1.0 * (x1 - x) * (x1 - x) + 1.0 * (y1 - y) * (y1 - y));
    dis -= 2 * r;
    int Ans = ceil(dis / (2 * r));
    printf("%d\n", Ans + 1);
    return 0;
}
