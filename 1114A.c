#include <stdio.h>

int main()
{
    int x, y, z;
    int a, b, c;
    scanf("%d %d %d", &x, &y, &z);
    scanf("%d %d %d", &a, &b, &c);
    if(a < x) {
        puts("NO");
    } else {
        a -= x;
        if(a + b < y) {
            puts("NO");
        } else {
            if(a + b + c < y + z) {
                puts("NO");
            } else {
                puts("YES");
            }
        }
    }
    return 0;
}
