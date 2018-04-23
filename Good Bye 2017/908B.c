#include <stdio.h>

int step[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main()
{
    int n, m;
    int Sx, Sy, Ex, Ey;
    char map[50][51];
    char str[101];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
        for(int j = 0; j < m; ++j) {
            if(map[i][j] == 'S') {
                Sx = i;
                Sy = j;
            }
            if(map[i][j] == 'E') {
                Ex = i;
                Ey = j;
            }
        }
    }
    scanf("%s", str);
    int ans = 0;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 4; ++k) {
                for(int l = 0; l < 4; ++l) {
                    if(i != j && i != k && i != l && j != k && j != l && k != l) {
                        int x = Sx;
                        int y = Sy;
                        for(int s = 0; str[s]; ++s) {
                            if(str[s] == '0') {
                                x += step[i][0];
                                y += step[i][1];
                            } else if(str[s] == '1') {
                                x += step[j][0];
                                y += step[j][1];
                            } else if(str[s] == '2') {
                                x += step[k][0];
                                y += step[k][1];
                            } else if(str[s] == '3') {
                                x += step[l][0];
                                y += step[l][1];
                            }
                            if(x == Ex && y == Ey) {
                                ++ans;
                                break;
                            }
                            if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] == '#') {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
