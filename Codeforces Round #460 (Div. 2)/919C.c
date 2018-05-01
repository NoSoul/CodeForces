#include <stdio.h>

char Map[2000][2001];
int main()
{
    int n, m, k, ans = 0;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%s", Map[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(Map[i][j] == '.') {
                int cur = 1;
                ++j;
                while(j < m && Map[i][j] == '.') {
                    ++cur;
                    ++j;
                }
                if(cur >= k) {
                    ans += cur - k + 1;
                }
            }
        }
    }
    if(k > 1) {
        for(int j = 0; j < m; ++j) {
            for(int i = 0; i < n; ++i) {
                if(Map[i][j] == '.') {
                    int cur = 1;
                    ++i;
                    while(i < n && Map[i][j] == '.') {
                        ++cur;
                        ++i;
                    }
                    if(cur >= k) {
                        ans += cur - k + 1;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
