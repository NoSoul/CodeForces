#include <stdio.h>

#define MAXN 100004

int  PNum[9600];
char Flag[MAXN];
int Cnt;
int Map[500][500];

void MakePrime()
{
    int i, j;
    for(i = 2; i < MAXN; ++i) {
        if(!Flag[i]) {
            PNum[Cnt++] = i;
            for(j = i + i; j < MAXN; j += i) {
                Flag[j] = 1;
            }
        }
    }
    return ;
}

int Fun(int x)
{
    int i;
    for(i = 0; i < Cnt; ++i) {
        if(PNum[i] >= x) {
            return PNum[i] - x;
        }
    }
}

int main()
{
    Cnt = 0;
    MakePrime();
    int N, M, i, j, Min, Sum;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        for(j = 0; j < M; ++j) {
            scanf("%d", &Map[i][j]);
            Map[i][j] = Fun(Map[i][j]);
        }
    }
    Min = 0x7fffffff;
    for(i = 0; i < N; ++i) {
        for(Sum = j = 0; j < M; ++j) {
            Sum += Map[i][j];
        }
        if(Sum < Min) {
            Min = Sum;
        }
    }
    for(j = 0; j < M; ++j) {
        for(Sum = i = 0; i < N; ++i) {
            Sum += Map[i][j];
        }
        if(Sum < Min) {
            Min = Sum;
        }
    }
    printf("%d\n", Min);
    return 0;
}

