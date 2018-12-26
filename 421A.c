#include <stdio.h>

int main()
{
    int n, a, b, c;
    int ans[101];
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 1; i <= n; ++i) {
        ans[i] = 2;
    }
    for(int i = 0; i < a; ++i) {
        scanf("%d", &c);
        ans[c] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
