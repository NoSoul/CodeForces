#include <stdio.h>

int main()
{
    int t, L, v, l, r;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d %d", &L, &v, &l, &r);
        printf("%d\n", L / v - r / v + (l - 1) / v);
    }
    return 0;
}
