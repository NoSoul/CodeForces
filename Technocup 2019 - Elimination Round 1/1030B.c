#include <stdio.h>

int main()
{
    int n, d, m;
    scanf("%d %d %d", &n, &d, &m);
    while(m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if((y - x >= -d && y - x <= d) && (y + x >= d && y + x <= 2 * n - d)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
