#include <stdio.h>
#include <string.h>

int main()
{
    int n, m;
    int p[10001];
    char flag[10001];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    while(m--) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        if(x < l || x > r) {
            puts("Yes");
        } else {
            int old = p[x];
            memset(flag, 0, sizeof(flag));
            for(int i = l; i <= r; ++i) {
                flag[p[i]] = 1;
            }
            int cnt = 0;
            for(int i = 1; i <= n; ++i) {
                if(flag[i]) {
                    if(cnt == (x - l)) {
                        puts(i == old ? "Yes" : "No");
                        break;
                    }
                    ++cnt;
                }
            }
        }
    }
    return 0;
}
