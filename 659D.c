#include <stdio.h>

typedef struct {
    int x, y;
} Point_t;
Point_t P[1000];

int Fun(Point_t a, Point_t b, Point_t c)
{
    if(a.x == b.x && a.y < b.y) {
        if(b.x > c.x && b.y == c.y) {
            return 1;
        }
    }
    if(a.x == b.x && a.y > b.y) {
        if(b.x < c.x && b.y == c.y) {
            return 1;
        }
    }
    if(a.x < b.x && a.y == b.y) {
        if(b.x == c.x && b.y < c.y) {
            return 1;
        }
    }
    if(a.x > b.x && a.y == b.y) {
        if(b.x == c.x && b.y > c.y) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int N, i, Ans = 0;
    scanf("%d", &N);
    for(i = 0; i <= N; ++i) {
        scanf("%d %d", &P[i].x, &P[i].y);
    }
    for(i = 1; i < N; ++i) {
        if(Fun(P[i - 1], P[i], P[i + 1])) {
            ++Ans;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
