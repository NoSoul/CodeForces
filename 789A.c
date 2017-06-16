#include <stdio.h>

int main()
{
    int n, k, ans = 0, num;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        ans += (num + k - 1) / k;
    }
    printf("%d\n", (ans + 1) / 2);
    return 0;
}
