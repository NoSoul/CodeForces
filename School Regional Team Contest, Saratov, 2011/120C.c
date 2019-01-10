#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, a, ans = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        for(int j = 0; j < 3; ++j) {
            if(a >= k) {
                a -= k;
            }
        }
        ans += a;
    }
    printf("%d\n", ans);
    return 0;
}
