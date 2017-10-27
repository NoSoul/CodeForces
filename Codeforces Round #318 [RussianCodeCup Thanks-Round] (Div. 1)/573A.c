#include <stdio.h>

int GCD(int a, int b)
{
    int temp;
    while(b) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main()
{
    int N, i, C;
    int A[100000];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    if(N == 1) {
        puts("Yes");
        return 0;
    }
    C = GCD(A[0], A[1]);
    for(i = 2; i < N; ++i) {
        C = GCD(C, A[i]);
    }
    for(i = 0; i < N; ++i) {
        A[i] /= C;
        while((A[i] & 1) == 0) {
            A[i] >>= 1;
        }
        while(A[i] % 3 == 0) {
            A[i] /= 3;
        }
        if(A[i] != 1) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
