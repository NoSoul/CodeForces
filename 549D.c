#include <stdio.h>

int Val;
char Map[100][101], Mat[100][100];

int Fun(int x, int y)
{
    int i, j;
    if(Map[x][y] == 'W') {
        if(Mat[x][y] != 1) {
            int offset = 1 - Mat[x][y];
            for(i = 0; i <= x; ++i) {
                for(j = 0; j <= y; ++j) {
                    Mat[i][j] += offset;
                }
            }
            return 1;
        }
    } else {
        if(Mat[x][y] != -1) {
            int offset = -1 - Mat[x][y];
            for(i = 0; i <= x; ++i) {
                for(j = 0; j <= y; ++j) {
                    Mat[i][j] += offset;
                }
            }
            return 1;
        }
    }
    return 0;
}

int main()
{
    int N, M, i, j, Ans = 0;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
    }
    int CurR = N - 1, CurC = M - 1;
    int CurRI = M - 1, CurCI = N - 1;
    while(CurR >= 0 || CurC >= 0) {
        if(CurR >= 0) {
            for(i = CurRI; i >= 0; --i) {
                if(Fun(CurR, i)) {
                    CurRI = i - 1;
                    --i;
                    ++Ans;
                    break;
                }
            }
            if(i == -1) {
                --CurR;
                CurRI = M - 1;
            }
        }
        if(CurC >= 0) {
            for(i = CurCI; i >= 0; --i) {
                if(Fun(i, CurC)) {
                    CurCI = i - 1;
                    --i;
                    ++Ans;
                    break;
                }
            }
            if(i == -1) {
                --CurC;
                CurCI = N - 1;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
