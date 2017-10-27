#include <stdio.h>

int A[1000][1000];

int main()
{
    int N, M, i, j, type, Sum;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            Sum += A[i][j] * A[j][i];
        }
    }
    Sum &= 1;
    scanf("%d", &M);
    while(M--) {
        scanf("%d", &type);
        if(type == 3) {
            printf("%d", Sum);
        } else {
            scanf("%d", &i);
            Sum ^= 1;
        }
    }
    return 0;
}
