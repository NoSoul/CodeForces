#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, ans = 0;
    int a[1001];
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int j = 0; j < n; ++j) {
        int idx = k + j;
        if(idx > n) {
            idx -= n;
        }
        if(a[idx]) {
            printf("%d\n", idx);
            break;
        }
    }
    return 0;
}
