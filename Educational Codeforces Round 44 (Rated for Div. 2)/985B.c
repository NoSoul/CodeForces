#include <stdio.h>
#include <string.h>

int main()
{
    int n, m;
    char map[2000][2001];
    int cur[2001], temp[2001];
    memset(cur, 0, sizeof(cur));
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cur[j] += map[i][j] - '0';
        }
    }
    for(int i = 0; i < n; ++i) {
        memcpy(temp, cur, sizeof(cur));
        for(int j = 0; j < m; ++j) {
            temp[j] -= map[i][j] - '0';
        }
        char ok = 1;
        for(int j = 0; j < m; ++j) {
            ok &= temp[j] > 0;
        }
        if(ok) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
