#include <stdio.h>

typedef long long LL_t;

int main()
{
    int N, i, Min, Max, MinCnt, MaxCnt;
    LL_t Ans;
    int A[200000];
    Min = 0x7fffffff;
    Max = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        if(A[i] > Max) {
            Max = A[i];
        }
        if(A[i] < Min) {
            Min = A[i];
        }
    }
    for(MaxCnt = MinCnt = i = 0; i < N; ++i) {
        if(A[i] == Max) {
            ++MaxCnt;
        }
        if(A[i] == Min) {
            ++MinCnt;
        }
    }
    if(Min == Max) {
        if(N == 2) {
            Ans = 1;
        } else {
            Ans = ((LL_t)N) * (N - 1) / 2;
        }
    } else {
        Ans = ((LL_t)MaxCnt) * MinCnt;
    }
    printf("%d %I64d\n", Max - Min, Ans);
    return 0;
}
