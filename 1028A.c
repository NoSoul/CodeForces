#include <stdio.h>

int main()
{
    int n, m, ansX, ansY;
    char map[115][116];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
        int s, e;
        s = e = -1;
        for(int j = 0; j < m; ++j) {
            if(map[i][j] == 'B') {
                s = j;
                break;
            }
        }
        if(~s) {
            for(int j = m - 1; j >= 0; --j) {
                if(map[i][j] == 'B') {
                    e = j;
                    break;
                }
            }
            ansY = (s + e) / 2;
        }
    }
    for(int j = 0; j < m; ++j) {
        int s, e;
        s = e = -1;
        for(int i = 0; i < n; ++i) {
            if(map[i][j] == 'B') {
                s = i;
                break;
            }
        }
        if(~s) {
            for(int i = n - 1; i >= 0; --i) {
                if(map[i][j] == 'B') {
                    e = i;
                    break;
                }
            }
            ansX = (s + e) / 2;
            break;
        }
    }
    printf("%d %d\n", ansX + 1, ansY + 1);
    return 0;
}
