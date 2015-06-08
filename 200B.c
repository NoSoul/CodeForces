#include <stdio.h>

int main()
{
    int N, P, Sum, i;
    scanf("%d", &N);
    for(Sum = i = 0; i < N; ++i) {
        scanf("%d", &P);
        Sum += P;
    }
    printf("%.12f\n", Sum * 1.0 / N);
    return 0;
}
