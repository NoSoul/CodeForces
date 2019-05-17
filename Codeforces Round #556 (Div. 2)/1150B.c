#include <stdio.h>

int N;
char Map[50][51];

int Check(int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y < N && Map[x][y] == '.') {
        return 1;
    }
    return 0;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(Map[i][j] == '.') {
                if(Check(i + 1, j - 1) && Check(i + 1, j) && Check(i + 1, j + 1) && Check(i + 2, j)) {
                    Map[i][j] = '#';
                    Map[i + 1][j - 1] = '#';
                    Map[i + 1][j] = '#';
                    Map[i + 1][j + 1] = '#';
                    Map[i + 2][j] = '#';
                } else {
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    puts("YES");
    return 0;
}
