#include <stdio.h>

int main()
{
    int A[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
    int N;
    scanf("%d", &N);
    printf("%d\n", A[N / 10]*A[N % 10]);
    return 0;
}
