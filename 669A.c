#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", (N / 3) * 2 + (N % 3 != 0));
    return 0;
}
