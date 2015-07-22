#include <stdio.h>

int A[1000001][3];

int main()
{
    int N, i, Num;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        if(A[Num][0] == 0) {
            A[Num][0] = 1;
            A[Num][1] = A[Num][2] = i + 1;
        } else {
            ++A[Num][0];
            A[Num][2] = i + 1;
        }
    }
    int max = 0, l, r;
    for(i = 1; i < 1000001; ++i) {
        if(A[i][0] > max) {
            max = A[i][0];
            l = A[i][1];
            r = A[i][2];
        } else if(A[i][0] == max) {
            if(A[i][2] - A[i][1] < r - l) {
                l = A[i][1];
                r = A[i][2];
            }
        }
    }
    printf("%d %d\n", l, r);
    return 0;
}
