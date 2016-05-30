#include <stdio.h>

typedef struct {
    int type;
    int r, c, x;
} Node_t;

int Mat[100][100][2];
Node_t Trun[10000];

int main()
{
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    for(int i = 0; i < Q; ++i) {
        scanf("%d", &Trun[i].type);
        if(Trun[i].type < 3) {
            scanf("%d", &Trun[i].r);
        } else {
            scanf("%d %d %d", &Trun[i].r, &Trun[i].c, &Trun[i].x);
        }
    }
    for(int i = Q - 1; i >= 0; --i) {
        if(Trun[i].type == 1) {
            --Trun[i].r;
            int backVal = Mat[Trun[i].r][M - 1][0];
            int backFlag = Mat[Trun[i].r][M - 1][1];
            for(int j = M - 1; j > 0; --j) {
                Mat[Trun[i].r][j][0] = Mat[Trun[i].r][j - 1][0];
                Mat[Trun[i].r][j][1] = Mat[Trun[i].r][j - 1][1];
            }
            Mat[Trun[i].r][0][0] = backVal;
            Mat[Trun[i].r][0][1] = backFlag;
        } else if(Trun[i].type == 2) {
            --Trun[i].r;
            int backVal = Mat[N - 1][Trun[i].r][0];
            int backFlag = Mat[N - 1][Trun[i].r][1];
            for(int j = N - 1; j > 0; --j) {
                Mat[j][Trun[i].r][0] = Mat[j - 1][Trun[i].r][0];
                Mat[j][Trun[i].r][1] = Mat[j - 1][Trun[i].r][1];
            }
            Mat[0][Trun[i].r][0] = backVal;
            Mat[0][Trun[i].r][1] = backFlag;
        } else {
            --Trun[i].r;
            --Trun[i].c;
            if(!Mat[Trun[i].r][Trun[i].c][1]) {
                Mat[Trun[i].r][Trun[i].c][1] = 1;
                Mat[Trun[i].r][Trun[i].c][0] = Trun[i].x;
            }
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            printf("%d ", Mat[i][j][0]);
        }
        puts("");
    }
    return 0;
}
