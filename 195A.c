#include <stdio.h>

int main()
{
    int a, b, c, sum, i, j;
    scanf("%d %d %d", &a, &b, &c);
    sum = a * c;
    for(i = 1; i <= sum / b; ++i) {
        j = sum - i * b;
        if(b * c >= j) {
            break;
        }
    }
    printf("%d\n", i);
    return 0;
}
