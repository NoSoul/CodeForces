#include <stdio.h>

char Valid[100];

int main()
{
    char Map[100][101];
    int N, M, i, j, Ans;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
    }
    for(Ans = j = 0; j < M; ++j) {
        int flag = 0;
        for(i = 0; i < N - 1; ++i) {
            if(Map[i][j] > Map[i + 1][j] && !Valid[i]) {
                flag = 1;
                break;
            }
        }
        Ans += flag;
        if(!flag) {
            for(i = 0; i < N - 1; ++i) {
                if(Map[i][j] < Map[i + 1][j]) {
                    Valid[i] = 1;
                }
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
