#include <stdio.h>

int main()
{
    int N, M, i, j, Min, Ans = 0;
    int C[100];
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        for(j = 0; j < M; ++j) {
            scanf("%d", &C[j]);
        }
        Min = C[0];
        for(j = 1; j < M; ++j) {
            if(C[j] < Min) {
                Min = C[j];
            }
        }
        if(Ans < Min) {
            Ans = Min;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
