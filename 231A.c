#include <stdio.h>

int main()
{
    int N, Sum, A, B, C, D;
    scanf("%d", &N);
    Sum = 0;
    while(N--) {
        scanf("%d %d %d", &A, &B, &C);
        D = A + B + C;
        if(D > 1) {
            ++Sum;
        }
    }
    printf("%d\n", Sum);
    return 0;
}
