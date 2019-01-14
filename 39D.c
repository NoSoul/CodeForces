#include <stdio.h>

typedef struct {
    int x, y, z;
} Point;

int main()
{
    Point a, b;
    scanf("%d %d %d %d %d %d", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z);
    if(a.z == b.z || a.x == b.x || a.y == b.y) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
