#include <stdio.h>

int main()
{
    int N, i, j;
    int A[101];
    scanf("%d", &N);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &j);
        A[j] = i;
    }
    for(i = 1; i < N; ++i) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[i]);
    return 0;
}
