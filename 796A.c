#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, k, ans = 0x7f7f7f7f;
    int a[100];
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    --m;
    for(int i = 0; i < n; ++i) {
        if(a[i] && k >= a[i]) {
            if(ans > abs(i - m) * 10) {
                ans = abs(i - m) * 10;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
