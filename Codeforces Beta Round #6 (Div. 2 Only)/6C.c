#include <stdio.h>

int main()
{
    int N, i, ASum = 0, BSum = 0;
    int A[100000];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        ASum += A[i];
    }
    for(i = N - 2; i >= 0; --i) {
        ASum -= A[i + 1];
        BSum += A[i + 1];
        if(ASum <= BSum) {
            printf("%d %d\n", i + 1, N - i - 1);
            return 0;
        } else {
            if(ASum - A[i] <= BSum) {
                printf("%d %d\n", i + 1, N - i - 1);
                return 0;
            }
        }
    }
    printf("1 %d\n", N - 1);
    return 0;
}
