#include <stdio.h>
#include <stdlib.h>

int GetSum(int n)
{
    return n + n * (n - 1) / 2;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int len = abs(a - b);
    printf("%d\n", GetSum(len / 2) + GetSum(len - len / 2));
    return 0;
}
