#include <stdio.h>
char Map[50][51];

int Fun(int x, int y)
{
    int i, j;
    char Flag[4] = {0};
    for(i = x; i < x + 2; ++i) {
        for(j = y; j < y + 2; ++j) {
            if(Map[i][j] == 'f') {
                Flag[0] = 1;
            } else if(Map[i][j] == 'a') {
                Flag[1] = 1;
            } else if(Map[i][j] == 'c') {
                Flag[2] = 1;
            } else if(Map[i][j] == 'e') {
                Flag[3] = 1;
            }
        }
    }
    return Flag[0] & Flag[1] & Flag[2] & Flag[3];
}

int main()
{
    int N, M, i, j;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
    }
    int Ans = 0;
    for(i = 0; i < N - 1; ++i) {
        for(j = 0; j < M - 1; ++j) {
            if(Fun(i, j)) {
                ++Ans;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
