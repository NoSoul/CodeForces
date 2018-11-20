#include <stdio.h>

#define MAX 101

char Map[MAX][MAX];
char Hash[MAX];

int main()
{
    int N, M, i, j, Max;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
    }
    for(j = 0; j < M; ++j) {
        Max = Map[0][j];
        for(i = 1; i < N; ++i) {
            if(Max < Map[i][j]) {
                Max = Map[i][j];
            }
        }
        for(i = 0; i < N; ++i) {
            if(Map[i][j] == Max) {
                Hash[i] = 1;
            }
        }
    }
    for(j = i = 0; i < N; ++i) {
        j += Hash[i];
    }
    printf("%d\n", j);
    return 0;
}
