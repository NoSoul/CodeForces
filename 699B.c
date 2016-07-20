#include <stdio.h>

char Map[1000][1001];
int Row[1001];
int Col[1001];

int main()
{
    int N, M, Sum = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
        for(int j = 0; j < M; ++j) {
            if(Map[i][j] == '*') {
                ++Row[i];
                ++Col[j];
                ++Sum;
            }
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            int cur = Row[i] + Col[j] - (Map[i][j] == '*');
            if(cur == Sum) {
                printf("YES\n%d %d\n", i + 1, j + 1);
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
