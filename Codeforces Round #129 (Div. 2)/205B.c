#include <stdio.h>

#define LL __int64

LL A[100001];

int main()
{
    LL N, i, Max, Pre, Now, Sum;
    scanf("%I64d %I64d", &N, &Pre);
    for(i = 1; i < N; ++i) {
        scanf("%I64d", &Now);
        if(Now < Pre) {
            A[i] = A[i - 1] + Pre - Now;
        }
        Pre = Now;
    }
    for(Sum = Max = 0, i = 1; i < N; ++i) {
        if(A[i] == 0) {
            Sum += Max;
            Max = 0;
        } else if(A[i] > Max) {
            Max = A[i];
        }
    }
    if(Max != 0) {
        Sum += Max;
    }
    printf("%I64d\n", Sum);
    return 0;
}
