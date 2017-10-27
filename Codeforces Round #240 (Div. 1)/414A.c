#include <stdio.h>

int main()
{
    int N, K, X, i, j;
    scanf("%d %d", &N, &K);
    if(N == 1) {
        if(K != 0) {
            printf("-1\n");
        } else {
            printf("1\n");
        }
        return 0;
    }
    if(K < N / 2) {
        printf("-1\n");
        return 0;
    }
    X = K - (N - 2) / 2;
    printf("%d %d ", X, 2 * X);
    for(i = 0, j = 1; i < N - 2; ++i, ++j) {
        while(j == X || j == 2 * X) {
            ++j;
        }
        printf("%d ", j);
    }
    return 0;
}
