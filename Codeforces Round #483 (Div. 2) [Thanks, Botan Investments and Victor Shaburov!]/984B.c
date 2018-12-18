#include <stdio.h>

int step[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int main()
{
    int n, m;
    char map[100][101];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(map[i][j] == '.') {
                map[i][j] = '0';
            }
            if(map[i][j] != '*') {
                int cur = 0;
                for(int k = 0; k < 8; ++k) {
                    int newX = i + step[k][0];
                    int newY = j + step[k][1];
                    if(newX >= 0 & newX < n && newY >= 0 && newY < m && map[newX][newY] == '*') {
                        ++cur;
                    }
                }
                if(cur != map[i][j] - '0') {
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    puts("YES");
    return 0;
}
