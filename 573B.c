#include <stdio.h>

int H[100000];
int A[100000];

int main()
{
    int N, i, Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &H[i]);
    }
    if(N < 3) {
        puts("1");
        return 0;
    }
    A[0] = 1;
    for(i = 1; i < N; ++i) {
        A[i] = H[i] < A[i - 1] + 1 ? H[i] : A[i - 1] + 1;
    }
    A[N - 1] = 1;
    for(i = N - 2; i >= 0; --i) {
        if(A[i] > A[i + 1] + 1) {
            A[i] = A[i + 1] + 1;
        }
    }
    for(i = 0; i < N; ++i) {
        if(Ans < A[i]) {
            Ans = A[i];
        }
    }
    printf("%d\n", Ans);
    return 0;
}
