#include <stdio.h>

int main()
{
    int n, s;
    int cur, pre;
    scanf("%d %d", &n, &s);
    pre = -s - 1;
    for(int i = 0; i < n; ++i) {
        int h, m;
        scanf("%d %d", &h, &m);
        cur = h * 60 + m;
        if(pre + 1 + 2 * s < cur) {
            break;
        }
        pre = cur;
    }
    int ans = pre + s + 1;
    printf("%d %d\n", ans / 60, ans % 60);
    return 0;
}
