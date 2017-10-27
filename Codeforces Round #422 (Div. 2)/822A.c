#include <stdio.h>

int Fun(int A)
{
    if(A == 1) {
        return 1;
    }
    return Fun(A - 1) * A;
}

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d\n", Fun(A < B ? A : B));
    return 0;
}
