#include <stdio.h>

int Step[4][2] = {{ -1, 0}, {0, -1}, {0, 1}, {1, 0}};
char Map[11][11];

int main()
{
    int N, M, i, j, k, x, y, cnt;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
    }
    for(cnt = i = 0; i < N; ++i) {
        for(j = 0; j < M; ++j) {
            if(Map[i][j] == 'W') {
                for(k = 0; k < 4; ++k) {
                    x = i + Step[k][0];
                    y = j + Step[k][1];
                    if(x >= 0 && x < N && y >= 0 && y < M && Map[x][y] == 'P') {
                        Map[x][y] = '.';
                        ++cnt;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
