#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, t1, t2, t3;
    scanf("%d %d %d %d %d %d", &x, &y, &z, &t1, &t2, &t3);
    int stairs = abs(x - y) * t1;
    int elevator = abs(x - z) * t2 + t3 + t3 + abs(x - y) * t2 + t3;
    puts(stairs < elevator ? "NO" : "YES");
    return 0;
}
