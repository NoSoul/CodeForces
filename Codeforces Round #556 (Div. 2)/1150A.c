#include <stdio.h>

int main()
{
    int n, m, r, s, b;
    int minS = 1000, maxB = 1;
    scanf("%d %d %d", &n, &m, &r);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &s);
        if(minS > s) {
            minS = s;
        }
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", &b);
        if(maxB < b) {
            maxB = b;
        }
    }
    if(maxB <= minS) {
        printf("%d\n", r);
    } else {
        printf("%d\n", r % minS + r / minS * maxB);
    }
    return 0;
}
