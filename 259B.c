#include <stdio.h>

int main()
{
    int i, j;
    int A[3][3];
    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 3; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    A[0][0] = (A[1][2] + A[2][1]) / 2;
    A[1][1] = A[0][0] + A[2][0] - A[1][2];
    A[2][2] = A[0][0] + A[1][0] - A[2][1];
    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 3; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
