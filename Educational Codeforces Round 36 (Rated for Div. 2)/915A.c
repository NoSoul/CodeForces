#include <stdio.h>

int main()
{
    int n, k, a, ans;
    scanf("%d %d", &n, &k);
    ans = k;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(k % a == 0) {
            if(ans > k / a) {
                ans = k / a;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
