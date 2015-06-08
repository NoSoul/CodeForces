#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;
Point P[10000];

typedef struct {
    Point p;
    int r;
} Rad;
Rad R;

double Distance(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main()
{
    int X1, X2, Y1, Y2, N, i, j, Cnt;
    scanf("%d %d %d %d %d", &X1, &Y1, &X2, &Y2, &N);
    if(X1 > X2) {
        X1 ^= X2 ^= X1 ^= X2;
    }
    if(Y1 > Y2) {
        Y1 ^= Y2 ^= Y1 ^= Y2;
    }
    for(Cnt = 0, i = Y1; i <= Y2; ++i, ++Cnt) {
        P[Cnt].x = X1;
        P[Cnt].y = i;
    }
    for(i = Y1; i <= Y2; ++i, ++Cnt) {
        P[Cnt].x = X2;
        P[Cnt].y = i;
    }
    for(i = X1 + 1; i < X2; ++i, ++Cnt) {
        P[Cnt].x = i;
        P[Cnt].y = Y1;
    }
    for(i = X1 + 1; i < X2; ++i, ++Cnt) {
        P[Cnt].x = i;
        P[Cnt].y = Y2;
    }
    for(i = 0; i < N; ++i) {
        scanf("%d %d %d", &R.p.x, &R.p.y, &R.r);
        for(j = 0; j < Cnt; ++j) {
            if(Distance(R.p, P[j]) <= R.r * R.r) {
                P[j] = P[Cnt - 1];
                --j;
                --Cnt;
            }
        }
    }
    printf("%d\n", Cnt);
    return 0;
}
