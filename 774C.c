#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n & 1) {
        n -= 3;
        putchar('7');
        for(int i = 0; i < n / 2; ++i) {
            putchar('1');
        }
    } else {
        for(int i = 0; i < n / 2; ++i) {
            putchar('1');
        }
    }
    return 0;
}
