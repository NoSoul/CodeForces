#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum = 0;
    int a[360];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int ans = sum;
    for(int i = 0; i < n; ++i) {
        int cur = 0;
        for(int j = 0; j < n; ++j) {
            cur += a[(i + j) % n];
            if(ans > abs(cur - (sum - cur))) {
                ans = abs(cur - sum + cur);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
