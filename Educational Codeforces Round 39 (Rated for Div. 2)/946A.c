#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, ans, a;
    scanf("%d", &n);
    ans = 0;
    while(n--) {
        scanf("%d", &a);
        ans += abs(a);
    }
    printf("%d\n", ans);
    return 0;
}
