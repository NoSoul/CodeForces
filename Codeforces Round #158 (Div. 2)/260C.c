#include <stdio.h>

typedef __int64 LL;

LL A[100001];

int main()
{
    int N, X, i;
    LL Min, Cnt, Sum;
    scanf("%d %d", &N, &X);
    for(Min = 0x7fffffff, i = 1; i <= N; ++i) {
        scanf("%I64d", &A[i]);
        if(A[i] < Min) {
            Min = A[i];
        }
    }
    Sum = Min * N;
    for(i = 1; i <= N; ++i) {
        A[i] -= Min;
    }
    for(Cnt = 0, i = X; i > 0; --i) {
        if(A[i] == 0) {
            break;
        }
        --A[i];
        ++Cnt;
    }
    if(i == 0) {
        for(i = N; i > X; --i) {
            if(A[i] == 0) {
                break;
            }
            --A[i];
            ++Cnt;
        }
        if(i > X) {
            A[i] = Sum + Cnt;
        }
    } else {
        A[i] = Sum + Cnt;
    }
    for(i = 1; i <= N; ++i) {
        printf("%I64d ", A[i]);
    }
    return 0;
}
