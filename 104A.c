#include <stdio.h>

int A[12] = {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 15, 4};

int main()
{
    int N;
    scanf("%d", &N);
    if(N <= 10 || N > 21)
    {
        puts("0");
        return 0;
    }
    printf("%d\n", A[N - 10]);
    return 0;
}
