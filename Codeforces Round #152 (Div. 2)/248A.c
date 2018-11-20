#include <stdio.h>

int main()
{
    int N, a, b, A, B, i;
    scanf("%d", &N);
    for(i = A = B = 0; i < N; ++i) {
        scanf("%d %d", &a, &b);
        A += a;
        B += b;
    }
    if(A > N / 2) {
        A = N - A;
    }
    if(B > N / 2) {
        B = N - B;
    }
    printf("%d\n", A + B);
    return 0;
}
