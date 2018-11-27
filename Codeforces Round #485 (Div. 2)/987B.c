#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    if(x == y) {
        puts("=");
    } else {
        if(y * log(x) > x * log(y)) {
            puts(">");
        } else if(y * log(x) < x * log(y)) {
            puts("<");
        } else {
            puts("=");
        }
    }
    return 0;
}
