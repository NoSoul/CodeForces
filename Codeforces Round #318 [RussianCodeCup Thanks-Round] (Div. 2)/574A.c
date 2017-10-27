#include <stdio.h>

int main()
{
    int N, Ans = 0, i;
    int A[100];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    while(1) {
        int max = A[1];
        int maxid = 1;
        for(i = 2; i < N; ++i) {
            if(A[i] > max) {
                max = A[i];
                maxid = i;
            }
        }
        if(max < A[0]) {
            break;
        }
        ++Ans;
        ++A[0];
        --A[maxid];
    }
    printf("%d\n", Ans);
    return 0;
}
