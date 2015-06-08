#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    if(x > 0 && y > 0) {
        printf("%d %d %d %d\n", 0, x + y, x + y, 0);
    } else if(x < 0 && y > 0) {
        printf("%d %d %d %d\n", x - y, 0, 0, -x + y);
    } else if(x < 0 && y < 0) {
        printf("%d %d %d %d\n", x + y, 0, 0, x + y);
    } else if(x > 0 && y < 0) {
        printf("%d %d %d %d\n", 0, y - x, x - y, 0);
    }
    return 0;
}
