#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if(x1 == x2) {
        printf("%d\n", (2 + abs(y1 - y2) + 1) * 2);
    } else if(y1 == y2) {
        printf("%d\n", (2 + abs(x1 - x2) + 1) * 2);
    } else {
        printf("%d\n", (abs(x1 - x2) + 1 + abs(y1 - y2) + 1) * 2);
    }
    return 0;
}
