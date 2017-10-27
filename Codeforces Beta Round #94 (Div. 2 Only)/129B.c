#include <stdio.h>

char Map[101][101];
int D[101];

int main()
{
    int N, M, i, j;
    int B[101], Len;
    scanf("%d %d", &N, &M);
    while(M--) {
        scanf("%d %d", &i, &j);
        Map[i][j] = Map[j][i] = 1;
        ++D[i];
        ++D[j];
    }
    int Ans = 0;
    while(1) {
        Len = 0;
        for(i = 1; i <= N; ++i) {
            if(D[i] == 1) {
                B[Len++] = i;
            }
        }
        if(Len == 0) {
            break;
        }
        for(i = 0; i < Len; ++i) {
            D[B[i]] = 0;
            for(j = 1; j <= N; ++j) {
                if(Map[B[i]][j]) {
                    Map[B[i]][j] = Map[j][B[i]] = 0;
                    --D[j];
                    break;
                }
            }
        }
        ++Ans;
    }
    printf("%d\n", Ans);
    return 0;
}
