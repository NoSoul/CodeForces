#include <stdio.h>

int main()
{
    int n, a, x, b, y;
    scanf("%d %d %d %d %d", &n, &a, &x, &b, &y);
    a %= n;
    x %= n;
    b %= n;
    y %= n;
    while(a != x && b != y) {
        a = (a + 1) % n;
        b = (b - 1 + n) % n;
        if(a == b) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
