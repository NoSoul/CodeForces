#include <stdio.h>

int main()
{
    int N, M, i, j, k;
    scanf("%d %d", &N, &M);
    j = N / M;
    k = N % M;
    for(i = 0; i < M; ++i, --k) {
        printf("%d ", k > 0 ? j + 1 : j);
    }
    return 0;
}
