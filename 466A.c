#include <stdio.h>

int main()
{
    int N, M, a, b;
    scanf("%d %d %d %d", &N, &M, &a, &b);
    if(a * M >= b) {
        if((N % M)*a <= b) {
            printf("%d\n", N / M * b + (N % M)*a);
        } else {
            printf("%d\n", N / M * b + b);
        }
    } else {
        printf("%d\n", N * a);
    }
    return 0;
}
