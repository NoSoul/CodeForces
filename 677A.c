#include <stdio.h>

int main()
{
    int n, h, a, ans = 0;
    scanf("%d %d", &n, &h);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++ans;
        if(a > h) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
