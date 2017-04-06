#include <stdio.h>

char flag[100001];

int main()
{
    int n, x, cur = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n; ++i) {
        scanf("%d", &x);
        if(!flag[x]) {
            flag[x] = 1;
            ++cur;
            if(ans < cur) {
                ans = cur;
            }
        } else {
            --cur;
        }
    }
    printf("%d\n", ans);
    return 0;
}
