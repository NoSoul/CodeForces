#include <stdio.h>

int main()
{
    int N, a, b;
    scanf("%d %d %d", &N, &a, &b);
    a = ((a - 1 + b) % N + N) % N + 1;
    printf("%d\n", a);
    return 0;
}
