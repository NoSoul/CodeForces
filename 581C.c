#include <stdio.h>

int A[10];

int main()
{
    int N, K, Sum, i, Num;
    Sum = 0;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        Sum += Num / 10;
        ++A[Num % 10];
    }
    for(i = 9; i > 0; --i) {
        int need = (10 - i) * A[i];
        if(K > need) {
            K -= need;
            Sum += A[i];
        } else {
            int only = K / (10 - i);
            K -= (10 - i) * only;
            Sum += only;
        }
    }
    Sum += K / 10;
    if(Sum > N * 10) {
        Sum = N * 10;
    }
    printf("%d\n", Sum);
    return 0;
}
