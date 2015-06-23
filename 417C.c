#include <stdio.h>

int Ans[500000][2];
char Map[1001][1001];
int Size;

int main()
{
    int N, K, i, j;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        int cur = 0;
        for(j = 0; j < N; ++j) {
            if(i != j && !Map[i][j]) {
                Map[i][j] = Map[j][i] = 1;
                Ans[Size][0] = i + 1;
                Ans[Size][1] = j + 1;
                ++Size;
                if(++cur == K) {
                    break;
                }
            }
        }
        if(cur != K) {
            puts("-1");
            return 0;
        }
    }
    printf("%d\n", Size);
    for(i = 0; i < Size; ++i) {
        printf("%d %d\n", Ans[i][0], Ans[i][1]);
    }
    return 0;
}
