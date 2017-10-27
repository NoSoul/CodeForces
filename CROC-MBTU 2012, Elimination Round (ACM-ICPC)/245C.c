#include <stdio.h>

int main()
{
    int N, i, Sum;
    int A[101];
    scanf("%d", &N);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    if(N < 3 || N % 2 == 0) {
        puts("-1");
    } else {
        for(Sum = 0, i = N; i >= 1; --i) {
            if(A[i] > 0) {
                Sum += A[i];
                A[i ^ 1] -= A[i];
                A[i >> 1] -= A[i];
            }
        }
        printf("%d\n", Sum);
    }
    return 0;
}
