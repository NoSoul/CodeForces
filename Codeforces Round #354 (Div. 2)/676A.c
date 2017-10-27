#include <stdio.h>

int main()
{
    int N, i, pA, pB;
    int A[100];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        if(A[i] == 1) {
            pA = i + 1;
        }
        if(A[i] == N) {
            pB = i + 1;
        }
    }
    int max = (pA > pB ? pA : pB) - 1;
    int min = pA < pB ? pA : pB;
    if(N - min > max) {
        max = N - min;
    }
    printf("%d\n", max);
    return 0;
}
