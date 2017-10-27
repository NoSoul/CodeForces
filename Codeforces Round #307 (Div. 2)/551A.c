#include <stdio.h>

int main()
{
    int A[2000];
    int N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < N; ++i) {
        int Ans = 1;
        for(j = 0; j < N; ++j) {
            if(i != j && A[j] > A[i]) {
                ++Ans;
            }
        }
        printf("%d ", Ans);
    }
    puts("");
    return 0;
}
