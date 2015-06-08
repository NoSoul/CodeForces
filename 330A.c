#include <stdio.h>

int main()
{
    int r, c, i, j, Cnt;
    char Map[11][11];
    scanf("%d %d", &r, &c);
    for(i = 0; i < r; ++i) {
        scanf("%s", Map[i]);
    }
    for(Cnt = i = 0; i < r; ++i) {
        for(j = 0; j < c; ++j) {
            if(Map[i][j] == 'S') {
                break;
            }
        }
        if(j == c) {
            for(j = 0; j < c; ++j) {
                if(Map[i][j] == '.') {
                    Map[i][j] = '#';
                    ++Cnt;
                }
            }
        }
    }
    for(i = 0; i < c; ++i) {
        for(j = 0; j < r; ++j) {
            if(Map[j][i] == 'S') {
                break;
            }
        }
        if(j == r) {
            for(j = 0; j < r; ++j) {
                if(Map[j][i] == '.') {
                    Map[j][i] = '#';
                    ++Cnt;
                }
            }
        }
    }
    printf("%d\n", Cnt);
    return 0;
}
