#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, Min, X, Y, Now;
    int A[100];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    X = 0;
    Y = 1;
    Min = abs(A[0] - A[1]);
    for(i = 1; i < N; ++i) {
        Now = abs(A[i] - A[(i + 1) % N]);
        if(Now < Min) {
            Min = Now;
            X = i;
            Y = (i + 1) % N;
        }
    }
    printf("%d %d\n", X + 1, Y + 1);
    return 0;
}
