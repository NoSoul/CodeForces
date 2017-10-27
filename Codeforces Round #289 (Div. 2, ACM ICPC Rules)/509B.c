#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K, i, j;
    int A[100];
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < N; ++i) {
        for(j = i + 1; j < N; ++j) {
            if(abs(A[i] - A[j]) > K) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for(i = 0; i < N; ++i) {
        for(j = 0; j < A[i]; ++j) {
            printf("%d ", (j % K) + 1);
        }
        puts("");
    }
    return 0;
}
