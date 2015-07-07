#include <stdio.h>
#include <stdlib.h>

long long A[4000];
long long B[4000];
int Map[2000][2000];
int N;

int GetIdxInA(int x, int y)
{
    return x + y;
}

int GetIdxInB(int x, int y)
{
    int xprime = y;
    int yprime = N - 1 - x;
    return xprime + yprime;
}

int main()
{
    int i, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            scanf("%d", &Map[i][j]);
            A[GetIdxInA(i, j)] += Map[i][j];
            B[GetIdxInB(i, j)] += Map[i][j];
        }
    }
    long long MaxB = -1, MaxW = -1;
    int MaxBI, MaxBJ, MaxWI, MaxWJ;
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            if(abs(i - j) & 1) {
                if(A[GetIdxInA(i, j)] + B[GetIdxInB(i, j)] - Map[i][j] > MaxB) {
                    MaxB = A[GetIdxInA(i, j)] + B[GetIdxInB(i, j)] - Map[i][j];
                    MaxBI = i;
                    MaxBJ = j;
                }
            } else {
                if(A[GetIdxInA(i, j)] + B[GetIdxInB(i, j)] - Map[i][j] > MaxW) {
                    MaxW = A[GetIdxInA(i, j)] + B[GetIdxInB(i, j)] - Map[i][j];
                    MaxWI = i;
                    MaxWJ = j;
                }
            }
        }
    }
    printf("%I64d\n", MaxB + MaxW);
    printf("%d %d %d %d\n", MaxBI + 1, MaxBJ + 1, MaxWI + 1, MaxWJ + 1);
    return 0;
}
