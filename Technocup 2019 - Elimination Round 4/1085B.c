#include <stdio.h>

int main()
{
    int n, k;
    int ans = 0x7fffffff;
    scanf("%d %d", &n, &k);
    for(int i = 1; i < k; ++i) {
        if(n % i == 0) {
            int cur = n / i * k + i;
            if(ans > cur) {
                ans = cur;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
