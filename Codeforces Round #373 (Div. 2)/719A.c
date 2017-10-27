#include <stdio.h>

int main()
{
    int N;
    int A[100];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    if(A[N - 1] == 0) {
        puts("UP");
    } else if(A[N - 1] == 15) {
        puts("DOWN");
    } else {
        if(N == 1) {
            puts("-1");
        } else {
            puts(A[N - 1] > A[N - 2] ? "UP" : "DOWN");
        }
    }
    return 0;
}
