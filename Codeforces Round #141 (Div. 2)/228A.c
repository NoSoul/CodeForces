#include <stdio.h>

int main()
{
    int i, j, k, Cnt;
    int A[4], R[4];
    scanf("%d %d %d %d", &A[0], &A[1], &A[2], &A[3]);
    R[0] = A[0];
    Cnt = 1;
    for(i = 1; i < 4; ++i) {
        for(j = 0; j < Cnt; ++j) {
            if(A[i] == R[j]) {
                break;
            }
        }
        if(j == Cnt) {
            R[Cnt] = A[i];
            ++Cnt;
        }
    }
    printf("%d\n", 4 - Cnt);
    return 0;
}
