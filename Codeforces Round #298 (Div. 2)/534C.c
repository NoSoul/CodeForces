#include <stdio.h>

int main()
{
    int N, i;
    int D[200000];
    long long A, Sum = 0;
    scanf("%d %I64d", &N, &A);
    for(i = 0; i < N; ++i) {
        scanf("%d", &D[i]);
        Sum += D[i];
    }
    for(i = 0; i < N; ++i) {
        long long curmin = A - (Sum - D[i]);
        long long curmax = A - (N - 1);
        if(curmin < 1) {
            curmin = 1;
        }
        if(curmax > D[i]) {
            curmax = D[i];
        }
        printf("%d ", D[i] - (curmax - curmin + 1));
    }
    printf("\n");
    return 0;
}
