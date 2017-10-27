#include <stdio.h>

int main()
{
    int N, K, i, Num, Sum;
    int A[6] = {0};
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        ++A[Num];
    }
    for(Sum = 0, i = 0; i < 6; ++i) {
        if(K + i > 5) {
            break;
        }
        Sum += A[i];
    }
    printf("%d\n", Sum / 3);
    return 0;
}
