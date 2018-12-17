#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n % 10 > 5) {
        n += 10;
    }
    n -= n % 10;
    printf("%d\n", n);
    return 0;
}
