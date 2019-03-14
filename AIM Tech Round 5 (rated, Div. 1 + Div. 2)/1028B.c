#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int cnt = n / 4;
    for(int i = 0; i < cnt; ++i) {
        putchar('4');
    }
    puts("5");
    for(int i = 0; i < cnt; ++i) {
        putchar('5');
    }
    puts("5");
    return 0;
}
