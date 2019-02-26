#include <stdio.h>

int main()
{
    int r, c, n, k;
    char Map[10][11];
    scanf("%d %d %d %d", &r, &c, &n, &k);
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            Map[i][j] = '.';
        }
    }
    for(int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        Map[x][y] = '#';
    }
    int ans = 0;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            for(int p = i; p < r; ++p) {
                for(int q = j; q < c; ++q) {
                    int cur = 0;
                    for(int l = i; l <= p; ++l) {
                        for(int m = j; m <= q; ++m) {
                            cur += Map[l][m] == '#';
                        }
                    }
                    if(cur >= k) {
                        ++ans;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
