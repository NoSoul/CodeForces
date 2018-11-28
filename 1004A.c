#include <stdio.h>

int main()
{
    int n, d, ans = 2;
    int x[100];
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    for(int i = 1; i < n; ++i) {
        if(x[i - 1] + d < x[i] - d) {
            ans += 2;
        } else if(x[i - 1] + d == x[i] - d) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
