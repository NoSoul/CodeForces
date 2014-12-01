#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if(N & 1)
    {
        printf("9 %d\n", N - 9);
    }
    else
    {
        printf("4 %d\n", N - 4);
    }
    return 0;
}
