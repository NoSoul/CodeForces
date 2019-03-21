#include <stdio.h>

int Cnt[1000][10001];

int main()
{
    int n, m;
    char Map[1000][1001];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", Map[i]);
    }
    for(int i = 1; i < n - 1; ++i) {
        for(int j = 1; j < m - 1; ++j) {
            if(Map[i - 1][j - 1] == '#' && Map[i - 1][j] == '#' && Map[i - 1][j + 1] == '#'
                    && Map[i][j - 1] == '#' && Map[i][j + 1] == '#'
                    && Map[i + 1][j - 1] == '#' && Map[i + 1][j] == '#' && Map[i + 1][j + 1] == '#') {
                ++Cnt[i - 1][j - 1];
                ++Cnt[i - 1][j];
                ++Cnt[i - 1][j + 1];
                ++Cnt[i][j - 1];
                ++Cnt[i][j + 1];
                ++Cnt[i + 1][j - 1];
                ++Cnt[i + 1][j];
                ++Cnt[i + 1][j + 1];
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(Map[i][j] == '#' && Cnt[i][j] == 0) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
