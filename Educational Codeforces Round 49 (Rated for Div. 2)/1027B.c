#include <stdio.h>

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    while(q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(((x & 1) && (y & 1)) || (!(x & 1) && !(y & 1))) {
            long long m = (long long)(x - 1) / 2 * ((n + 1) / 2 + n / 2);
            if(x & 1) {
                printf("%I64d\n", m + (y + 1) / 2);
            } else {
                printf("%I64d\n", m + (n + 1) / 2 + y / 2);
            }
        } else {
            long long m = ((long long)n * n + 1) / 2 + (long long)(x - 1) / 2 * ((n + 1) / 2 + n / 2);
            if(x & 1) {
                printf("%I64d\n", m + y / 2);
            } else {
                printf("%I64d\n", m + n / 2 + (y + 1) / 2);
            }
        }
    }
    return 0;
}
