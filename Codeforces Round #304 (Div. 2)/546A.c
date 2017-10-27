#include <stdio.h>

int main()
{
    int k, w, n;
    scanf("%d %d %d", &k, &n, &w);
    n -= (k + w * k) * w / 2;
    if(n > 0) {
        n = 0;
    }
    printf("%d\n", -n);
    return 0;
}
