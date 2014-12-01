#include <stdio.h>
#include <math.h>

typedef struct
{
    int x, y;
} Point;

double Distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    int N, K, i;
    double Dist;
    Point Pre, Now;
    scanf("%d %d %d %d", &N, &K, &Pre.x, &Pre.y);
    for(Dist = 0, i = 1; i < N; ++i)
    {
        scanf("%d %d", &Now.x, &Now.y);
        Dist += Distance(Pre, Now);
        Pre = Now;
    }
    printf("%.9f\n", K * Dist / 50);
    return 0;
}
