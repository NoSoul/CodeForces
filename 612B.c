#include <stdio.h>
#include <stdlib.h>

int A[200001];

int main()
{
    int N, i, f;
    long long Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &f);
        A[f] = i;
    }
    for(i = 2; i <= N; ++i) {
        Ans += abs(A[i] - A[i - 1]);
    }
    printf("%I64d\n", Ans);
    return 0;
}
