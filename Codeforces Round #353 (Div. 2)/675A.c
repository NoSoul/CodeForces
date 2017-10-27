#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == b) {
        puts("YES");
    } else {
        if(c == 0) {
            puts("NO");
        } else if(c > 0) {
            puts(b > a && (b - a) % c == 0 ? "YES" : "NO");
        } else {
            puts(b < a && (b - a) % c == 0 ? "YES" : "NO");
        }
    }
    return 0;
}
