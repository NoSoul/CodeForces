#include <stdio.h>

#define MAXN    500001

typedef __int64 LL_t;

int A[MAXN];
LL_t B[MAXN];
int C[MAXN];
LL_t Sum, Ans;

int main()
{
    int N, i;
    scanf("%d\n", &N);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        B[i] = B[i - 1] + A[i - 1];
        Sum += A[i];
    }
    if(Sum % 3) {
        printf("0\n");
        return 0;
    }
    int Cnt = 0;
    for(i = 2; i < N; ++i) {
        if(B[i] == Sum / 3) {
            ++Cnt;
        }
        C[i] = Cnt;
    }
    Ans = 0;
    for(i = 2; i < N; ++i) {
        if(B[i + 1] == Sum / 3 * 2) {
            Ans += C[i];
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
