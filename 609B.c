#include <stdio.h>

int A[10];

int main()
{
    int N, M, i, j, num;
    long long Ans = 0;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%d", &num);
        ++A[num - 1];
    }
    for(i = 0; i < M - 1; ++i) {
        for(j = i + 1; j < M; ++j) {
            Ans += (long long)A[i] * A[j];
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
