#include <stdio.h>

int main()
{
    int n, x;
    long long k;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%I64d %d", &k, &x);
        if(k == 1) {
            printf("%d\n", x);
        } else {
            --k;
            printf("%I64d\n", k * 9 + x);
        }
    }
    return 0;
}
