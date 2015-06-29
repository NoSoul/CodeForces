#include <stdio.h>

int main()
{
    int N, i;
    int A[1000];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    while(1) {
        if(A[0] == 0) {
            break;
        }
        for(i = 0; i < N; ++i) {
            if(i & 1) {
                A[i] = (A[i] - 1 + N) % N;
            } else {
                A[i] = (A[i] + 1) % N;
            }
        }
    }
    for(i = 0; i < N; ++i) {
        if(A[i] != i) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
