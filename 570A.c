#include <stdio.h>

int A[101];

int main()
{
    int N, M, i, j, Num;
    scanf("%d %d", &N, &M);
    int maxid, max;
    for(i = 0; i < M; ++i) {
        max = -1;
        for(j = 0; j < N; ++j) {
            scanf("%d", &Num);
            if(Num > max) {
                max = Num;
                maxid = j + 1;
            }
        }
        ++A[maxid];
    }
    max = -1;
    for(i = 1; i <= N; ++i) {
        if(A[i] > max) {
            max = A[i];
        }
    }
    for(i = 1; i <= N; ++i) {
        if(A[i] == max) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
