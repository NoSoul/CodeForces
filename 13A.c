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
    int N, i, j;
    int A, B;
    scanf("%d", &N);
    A = B = 0;
    for(i = 2; i < N; ++i, ++B) {
        j = N;
        while(j) {
            A += j % i;
            j /= i;
        }
    }
    printf("%d/%d\n", A / GCD(A, B), B / GCD(A, B));
    return 0;
}
