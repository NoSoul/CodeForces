#include <stdio.h>

int main()
{
    char Map[100][101];
    int N, i, j, k, Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
    }
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            if(Map[i][j] == 'C') {
                for(k = 0; k < N; ++k) {
                    if(Map[i][k] == 'C' && k != j) {
                        ++Ans;
                    }
                }
                for(k = 0; k < N; ++k) {
                    if(Map[k][j] == 'C' && k != i) {
                        ++Ans;
                    }
                }
            }
        }
    }
    printf("%d\n", Ans / 2);
    return 0;
}
