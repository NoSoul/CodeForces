#include <stdio.h>

int main()
{
    int R, C;
    char map[500][501];
    int step[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i) {
        scanf("%s", &map[i]);
    }
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(map[i][j] == 'S') {
                for(int k = 0; k < 4; ++k) {
                    int newX = i + step[k][0];
                    int newY = j + step[k][1];
                    if(newX >= 0 & newX < R && newY >= 0 && newY < C && map[newX][newY] == 'W') {
                        puts("No");
                        return 0;
                    }
                }
            }
        }
    }
    puts("Yes");
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(map[i][j] == '.') {
                map[i][j] = 'D';
            }
        }
        puts(map[i]);
    }
    return 0;
}
