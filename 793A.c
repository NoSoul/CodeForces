#include <stdio.h>

int main()
{
    int n, k;
    int a[100000];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int min = a[0];
    for(int i = 1; i < n; ++i) {
        if(min > a[i]) {
            min = a[i];
        }
        if(a[i] % k != a[0] % k) {
            puts("-1");
            return 0;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += (a[i] - min) / k;
    }
    printf("%I64d\n", ans);
    return 0;
}
