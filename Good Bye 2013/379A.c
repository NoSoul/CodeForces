#include <stdio.h>

int main()
{
    int a, b, sum;
    scanf("%d %d", &a, &b);
    sum = a;
    while(a >= b) {
        sum += a / b;
        a = a / b + a % b;
    }
    printf("%d\n", sum);
    return 0;
}
