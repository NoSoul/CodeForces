#include <stdio.h>

int main()
{
    int n, s, d, ans = 0;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &s, &d);
        if(ans < s) {
            ans = s;
        } else {
            ans = s + ((ans - s) / d + 1) * d;
        }
    }
    printf("%d\n", ans);
    return 0;
}
