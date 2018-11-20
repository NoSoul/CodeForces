#include <stdio.h>

int A[1000];

int main()
{
    int N, K, i, j, k;
    int B[30];
    scanf("%d %d", &N, &K);
    for(i = 0; i < K; ++i) {
        scanf("%d", &B[i]);
        A[B[i]] = i + 1;
    }
    for(i = j = 1; i <= K; ++i) {
        printf("%d ", B[i - 1]);
        k = N - 1;
        for(; k && j <= N * K; ++j) {
            if(A[j] == 0) {
                A[j] = i;
                --k;
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}
