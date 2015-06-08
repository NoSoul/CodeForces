#include <stdio.h>

#define min(a, b)   ((a)<(b)?(a):(b))
#define max(a, b)   ((a)>(b)?(a):(b))

int main()
{
    int N, x, y, minx, maxx, miny, maxy;
    scanf("%d", &N);
    minx = miny = 1000000000;
    maxx = maxy  = -1000000000;
    while(N--) {
        scanf("%d %d", &x, &y);
        maxx = max(x, maxx);
        maxy = max(y, maxy);
        minx = min(x, minx);
        miny = min(y, miny);
    }
    maxy -= miny;
    maxx -= minx;
    maxy = max(maxy, maxx);
    printf("%I64d\n", (long long)maxy * maxy);
    return 0;
}
