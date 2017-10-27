#include <stdio.h>

int Row[5000][2];
int Col[5000][2];

int main()
{
    int N, M, K, type, num, a, i, j;
    scanf("%d %d %d", &N, &M, &K);
    for(i = 1; i <= K; ++i) {
        scanf("%d %d %d", &type, &num, &a);
        --num;
        if(type == 1) {
            Row[num][0] = i;
            Row[num][1] = a;
        } else {
            Col[num][0] = i;
            Col[num][1] = a;
        }
    }
    for(i = 0; i < N; ++i) {
        for(j = 0; j < M; ++j) {
            if(Row[i][0] == 0 && Col[j][0] == 0) {
                printf("0 ");
            } else {
                printf("%d ", Row[i][0] > Col[j][0] ? Row[i][1] : Col[j][1]);
            }
        }
        puts("");
    }
    return 0;
}
