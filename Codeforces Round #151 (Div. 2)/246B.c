#include <stdio.h>

int main()
{
    int N, i, Num, Sum;
    scanf("%d", &N);
    for(Sum = i = 0; i < N; ++i) {
        scanf("%d", &Num);
        Sum += Num;
    }
    if(Sum % N == 0) {
        printf("%d\n", N);
    } else {
        printf("%d\n", N - 1);
    }
    return 0;
}
