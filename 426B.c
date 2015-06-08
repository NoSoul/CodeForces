#include <stdio.h>

int Mat[100][100];
int M;

int Judge(int N)
{
    int i, j, k;
    for(i = 0, j = N - 1; i < (N >> 1); ++i, --j) {
        for(k = 0; k < M; ++k) {
            if(Mat[i][k] != Mat[j][k]) {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int N, i, j;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        for(j = 0; j < M; ++j) {
            scanf("%d", &Mat[i][j]);
        }
    }
    while(1) {
        if(N & 1) {
            printf("%d\n", N);
            return 0;
        }
        if(Judge(N)) {
            N >>= 1;
        } else {
            printf("%d\n", N);
            return 0;
        }
    }
    return 0;
}
