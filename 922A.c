#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    if(y == 0) {
        puts("No");
        return 0;
    }
    if(y == 1) {
        puts(x ? "No" : "Yes");
        return 0;
    }
    x -= y - 1;
    puts((x >= 0 && x % 2 == 0) ? "Yes" : "No");
    return 0;
}
