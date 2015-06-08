#include <stdio.h>

int main()
{
    int i, N;
    int A[7];
    scanf("%d", &N);
    for(i = 0; i < 7; ++i) {
        scanf("%d", &A[i]);
    }
    for(i = 0;; i = (i + 1) % 7) {
        if(N <= A[i]) {
            break;
        }
        N -= A[i];
    }
    printf("%d\n", i + 1);
    return 0;
}
