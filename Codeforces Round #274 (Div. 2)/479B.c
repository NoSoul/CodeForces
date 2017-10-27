#include <stdio.h>

int main()
{
    int N, K, i, Size;
    int minid, maxid, min, max;
    int A[100], Ans[1000][2];
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    Size = 0;
    while(K--) {
        min = 0x3f3f3f3f;
        max = 0;
        for(i = 0; i < N; ++i) {
            if(A[i] > max) {
                max = A[i];
                maxid = i;
            }
            if(A[i] < min) {
                min = A[i];
                minid = i;
            }
        }
        if(max - min < 2) {
            break;
        }
        Ans[Size][0] = maxid;
        Ans[Size++][1] = minid;
        --A[maxid];
        ++A[minid];
    }
    min = 0x3f3f3f3f;
    max = 0;
    for(i = 0; i < N; ++i) {
        if(A[i] > max) {
            max = A[i];
            maxid = i;
        }
        if(A[i] < min) {
            min = A[i];
            minid = i;
        }
    }
    printf("%d %d\n", max - min, Size);
    for(i = 0; i < Size; ++i) {
        printf("%d %d\n", Ans[i][0] + 1, Ans[i][1] + 1);
    }
    return 0;
}
