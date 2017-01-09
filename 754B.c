#include <stdio.h>

char Map[4][5];

int OK()
{
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            int x1, y1, x2, y2;
            x1 = i;
            y1 = j + 1;
            x2 = i;
            y2 = j + 2;
            if(x1 >= 0 && x1 < 4 && y1 >= 0 && y1 < 4 && x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4 && Map[i][j] == 'x' && Map[x1][y1] == 'x' && Map[x2][y2] == 'x') {
                return 1;
            }
            x1 = i + 1;
            y1 = j;
            x2 = i + 2;
            y2 = j;
            if(x1 >= 0 && x1 < 4 && y1 >= 0 && y1 < 4 && x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4 && Map[i][j] == 'x' && Map[x1][y1] == 'x' && Map[x2][y2] == 'x') {
                return 1;
            }
            x1 = i + 1;
            y1 = j + 1;
            x2 = i + 2;
            y2 = j + 2;
            if(x1 >= 0 && x1 < 4 && y1 >= 0 && y1 < 4 && x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4 && Map[i][j] == 'x' && Map[x1][y1] == 'x' && Map[x2][y2] == 'x') {
                return 1;
            }
            x1 = i + 1;
            y1 = j - 1;
            x2 = i + 2;
            y2 = j - 2;
            if(x1 >= 0 && x1 < 4 && y1 >= 0 && y1 < 4 && x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4 && Map[i][j] == 'x' && Map[x1][y1] == 'x' && Map[x2][y2] == 'x') {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    for(int i = 0; i < 4; ++i) {
        scanf("%s", Map[i]);
    }
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(Map[i][j] == '.') {
                Map[i][j] = 'x';
                if(OK()) {
                    puts("YES");
                    return 0;
                }
                Map[i][j] = '.';
            }
        }
    }
    puts("NO");
    return 0;
}
