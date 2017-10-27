#include <stdio.h>

int main()
{
    int k, d;
    scanf("%d %d", &k, &d);
    if(k > 1 && d == 0) {
        puts("No solution\n");
        return 0;
    }
    printf("%d", d);
    while(--k) {
        putchar('0');
    }
    return 0;
}
