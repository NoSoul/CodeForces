#include <stdio.h>

int main()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if(x > y + z) {
        puts("+");
    } else if(y > x + z) {
        puts("-");
    } else if(z == 0 && x == y) {
        puts("0");
    } else {
        puts("?");
    }
    return 0;
}
