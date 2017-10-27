#include <stdio.h>

int main()
{
    int n, m;
    int minA, maxA, minB, maxB;
    int l, r;
    scanf("%d", &n);
    minA = minB = 0x7fffffff;
    maxA = maxB = 0;
    while(n--) {
        scanf("%d %d", &l, &r);
        if(minA > r) {
            minA = r;
        }
        if(maxA < l) {
            maxA = l;
        }
    }
    scanf("%d", &m);
    while(m--) {
        scanf("%d %d", &l, &r);
        if(minB > r) {
            minB = r;
        }
        if(maxB < l) {
            maxB = l;
        }
    }
    int ans = 0;
    if(ans < maxA - minB) {
        ans = maxA - minB;
    }
    if(ans < maxB - minA) {
        ans = maxB - minA;
    }
    printf("%d\n", ans);
    return 0;
}
