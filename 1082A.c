#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, x, y, d;
        scanf("%d %d %d %d", &n, &x, &y, &d);
        if(abs(x - y) % d == 0) {
            printf("%d\n", abs(x - y) / d);
        } else {
            if((y - 1) % d == 0 && (n - y) % d == 0) {
                int pre = (x - 1 + d - 1) / d + (y - 1) / d;
                int suf = (n - x + d - 1) / d + (n - y) / d;
                printf("%d\n", pre < suf ? pre : suf);
            } else if((y - 1) % d == 0) {
                printf("%d\n", (x - 1 + d - 1) / d + (y - 1) / d);
            } else if((n - y) % d == 0) {
                printf("%d\n", (n - x + d - 1) / d + (n - y) / d);
            } else {
                puts("-1");
            }
        }
    }
    return 0;
}
