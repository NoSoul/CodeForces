#include <stdio.h>

int main()
{
    int N;
    int A[100];
    int B[100];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        B[i] = i + 1;
    }
    for(int i = 0; i < N; ++i) {
        int k = i;
        for(int j = i + 1; j < N; ++j) {
            if(A[j] < A[k]) {
                k = j;
            }
        }
        if(k != i) {
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
            temp = B[i];
            B[i] = B[k];
            B[k] = temp;
        }
    }
    for(int i = 0; i < N / 2; ++i) {
        printf("%d %d\n", B[i], B[N - 1 - i]);
    }
    return 0;
}
