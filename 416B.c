#include <stdio.h>

int main()
{
    int M, N, i, j;
    int Mat[50000][5];
    int Map[5][50000];
    scanf("%d %d", &M, &N);
    for(i = 0; i < M; ++i) {
        for(j = 0; j < N; ++j) {
            scanf("%d", &Mat[i][j]);
        }
    }
    Map[0][0] = Mat[0][0];
    for(j = 1; j < M; ++j) {
        Map[0][j] = Map[0][j - 1] + Mat[j][0];
    }
    for(i = 1; i < N; ++i) {
        Map[i][0] = Map[i - 1][0] + Mat[0][i];
        for(j = 1; j < M; ++j) {
            int Max = Map[i][j - 1] > Map[i - 1][j] ? Map[i][j - 1] : Map[i - 1][j];
            Map[i][j] = Max + Mat[j][i];
        }
    }
    for(i = 0; i < M; ++i) {
        printf("%d ", Map[N - 1][i]);
    }
    return 0;
}
