#include <stdio.h>

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int min = a < b ? a : b;
    int map[3][3] = {
        0, -1, a,
        -1, 0, b,
        a, b, 2 * min,
    };
    int c[20];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    int ans = 0;
    for(int i = 0, j = n - 1; i <= j; ++i, --j) {
        if(i != j) {
            if(map[c[i]][c[j]] == -1) {
                puts("-1");
                return 0;
            } else {
                ans += map[c[i]][c[j]];
            }
        } else {
            if(c[i] == 2) {
                ans += min;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
