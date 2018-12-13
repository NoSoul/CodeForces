#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ans = n == 1 ? 1 : 2;
    if(n / 2 >= 2) {
        ans += n / 2 - 2 + 1;
    }
    printf("%d\n", ans);
    return 0;
}
