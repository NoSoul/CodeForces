#include <stdio.h>

typedef struct
{
    int x, y;
} Point_t;

int Fun(long long a, long long b, long  c, Point_t h, Point_t s)
{
    return (b * h.y > -a * h.x - c && b * s.y < -a * s.x - c) ||
           (b * h.y < -a * h.x - c && b * s.y > -a * s.x - c);
}

int main()
{
    Point_t h, s;
    int N, i, Ans = 0;
    scanf("%d %d %d %d", &h.x, &h.y, &s.x, &s.y);
    scanf("%d", &N);
    int a, b, c;
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(Fun(a, b, c, h, s))
        {
            ++Ans;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
