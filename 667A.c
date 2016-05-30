#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main()
{
    int d, h, v, e;
    double ans;
    scanf("%d %d %d %d", &d, &h, &v, &e);
    ans = (double)e * d * d * PI;
    if(ans >= 4 * v) {
        puts("NO");
        return 0;
    }
    ans = (double)h * d * d * PI;
    ans /= 4 * v - (double)e * d * d * PI;
    puts("YES");
    printf("%lf\n", ans);
    return 0;
}
