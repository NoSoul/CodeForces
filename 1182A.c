#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n & 1) {
        puts("0");
    } else {
        printf("%d\n", 1 << (n / 2));
    }
    return 0;
}
