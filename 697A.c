#include <stdio.h>

int main()
{
    int t, s, x;
    scanf("%d %d %d", &t, &s, &x);
    if(x < t) {
        puts("NO");
        return 0;
    }
    x -= t;
    if(x == 0 || (x >= s && (x % s == 0 || x % s == 1))) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
