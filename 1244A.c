#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        int x = (a + c - 1) / c;
        int y = (b + d - 1) / d;
        if(x + y > k) {
            puts("-1");
        } else {
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}
