#include <stdio.h>

int main()
{
    int n, k, t, ans = 0;
    int a[100001];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if(t) {
            ans += a[i];
            a[i] = 0;
        }
    }
    int cur = 0;
    for(int i = 0; i < k; ++i) {
        cur += a[i];
    }
    int max = cur;
    for(int i = 1; i + k <= n; ++i) {
        cur -= a[i - 1];
        cur += a[i + k - 1];
        if(max < cur) {
            max = cur;
        }
    }
    printf("%d\n", ans + max);
    return 0;
}
