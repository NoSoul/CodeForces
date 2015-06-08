#include <stdio.h>

int Fun(int u, int v, int d)
{
    int value = u - v < 0 ? v - u : u - v ;
    if(value % d) {
        return -1;
    }
    return value / d;
}

int main()
{
    int N, M, D, i, j, k, Min, Max, Ans, Now;
    int A[100][100];
    scanf("%d %d %d", &N, &M, &D);
    Min = 10001;
    Max = 0;
    for(i = 0; i < N; ++i) {
        for(j = 0; j < M; ++j) {
            scanf("%d", &A[i][j]);
            if(A[i][j] < Min) {
                Min = A[i][j];
            }
            if(A[i][j] > Max) {
                Max = A[i][j];
            }
        }
    }
    Ans = 0x7fffffff;
    for(k = Min; k <= Max; k += D) {
        char Flag = 1;
        Now = 0;
        for(i = 0; Flag && i < N; ++i) {
            for(j = 0; Flag && j < M; ++j) {
                if(Fun(A[i][j], k, D) == -1) {
                    Flag = 0;
                } else {
                    Now += Fun(A[i][j], k, D);
                }
            }
        }
        if(Flag) {
            if(Now < Ans) {
                Ans = Now;
            }
        }
    }
    if(Ans == 0x7fffffff) {
        Ans = -1;
    }
    printf("%d\n", Ans);
    return 0;
}
