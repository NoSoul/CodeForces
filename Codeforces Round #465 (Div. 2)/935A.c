#include <stdio.h>

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n / 2; ++i) {
        if(n % i == 0) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
