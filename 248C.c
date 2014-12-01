#include <stdio.h>
#include <math.h>

#define eps 1e-10

int main()
{
    double y1, y2, yw, xb, yb, r, Ans, Y, D;
    while(scanf("%lf %lf %lf %lf %lf %lf", &y1, &y2, &yw, &xb, &yb, &r) != EOF)
    {
        yw -= r;
        y1 += r;
        Ans = (yw - y1) * xb / (2 * yw - y1 - yb);
        Y = ((xb - Ans) * yw - (yw - yb) * Ans) / (xb - Ans);
        Y = y2 - Y;
        D = Y * (xb - Ans) / sqrt((xb - Ans) * (xb - Ans) + (yw - yb) * (yw - yb));
        if(D - r <= eps)
        {
            printf("-1\n");
            continue;
        }
        printf("%.10f\n", Ans);
    }
    return 0;
}
