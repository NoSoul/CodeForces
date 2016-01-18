#include <stdio.h>

char Map[500][501];
int Row[500][500];
int Col[500][500];

int main()
{
    int h, w, q, r1, c1, r2, c2, i, j;
    scanf("%d %d", &h, &w);
    for(i = 0; i < h; ++i) {
        scanf("%s", Map[i]);
    }
    for(i = 0; i < h; ++i) {
        for(j = 1; j < w; ++j) {
            Row[i][j] = Row[i][j - 1] + (Map[i][j - 1] == '.' && Map[i][j] == '.');
        }
    }
    for(j = 0; j < w; ++j) {
        for(i = 1; i < h; ++i) {
            Col[i][j] = Col[i - 1][j] + (Map[i - 1][j] == '.' && Map[i][j] == '.');
        }
    }
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        --r1;
        --c1;
        --r2;
        --c2;
        int cur = 0;
        for(i = r1; i <= r2; ++i) {
            cur += Row[i][c2] - Row[i][c1];
        }
        for(i = c1; i <= c2; ++i) {
            cur += Col[r2][i] - Col[r1][i];
        }
        printf("%d\n", cur);
    }
    return 0;
}
