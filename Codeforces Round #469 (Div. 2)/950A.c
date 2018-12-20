#include <stdio.h>

int main()
{
    int l, r, a;
    scanf("%d %d %d", &l, &r, &a);
    if(l > r) {
        int remain = l - r;
        if(a >= remain) {
            a -= remain;
            r += remain;
        } else {
            r += a;
            a = 0;
        }
    } else if(l < r) {
        int remain = r - l;
        if(a >= remain) {
            a -= remain;
            l += remain;
        } else {
            l += a;
            a = 0;
        }
    }
    if(a == 0) {
        printf("%d\n", (l < r ? l : r) * 2);
    } else {
        printf("%d\n", (l + a / 2) * 2);
    }
    return 0;
}
