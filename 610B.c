#include <stdio.h>

int A[200000];

int main()
{
    int N, i, j, Min = 0x7fffffff;
    long long Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        if(A[i] < Min) {
            Min = A[i];
        }
    }
    Ans = (long long)N * Min;
    for(i = 0; i < N; ++i) {
        A[i] -= Min;
    }
    for(i = 0; i < N; ++i) {
        if(A[i] == 0) {
            break;
        }
    }
    int cur = 0, Max = 0;
    for(j = 0; j < N; ++j) {
        if(A[i]) {
            ++cur;
        } else {
            if(cur > Max) {
                Max = cur;
            }
            cur = 0;
        }
        i = (i + 1) % N;
    }
    if(cur > Max) {
        Max = cur;
    }
    Ans += Max;
    printf("%I64d\n", Ans);
    return 0;
}
