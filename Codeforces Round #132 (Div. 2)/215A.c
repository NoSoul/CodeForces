#include <stdio.h>

int A[50], B[50];

int main()
{
    int N, M, i, j, Max, now, Cnt;
    while(scanf("%d", &N) != EOF) {
        for(i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        scanf("%d", &M);
        for(i = 0; i < M; ++i) {
            scanf("%d", &B[i]);
        }
        for(Max = i = 0; i < N; ++i) {
            for(j = 0; j < M; ++j) {
                now = B[j] / A[i];
                if(now * A[i] == B[j] && Max < now) {
                    Max = now;
                }
            }
        }
        for(Cnt = i = 0; i < N; ++i) {
            for(j = 0; j < M; ++j) {
                now = B[j] / A[i];
                if(now * A[i] == B[j] && Max == now) {
                    ++Cnt;
                }
            }
        }
        printf("%d\n", Cnt);
    }
    return 0;
}
