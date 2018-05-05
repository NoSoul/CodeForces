#include <stdio.h>

int main()
{
    int k, cnt6, cnt8;
    scanf("%d", &k);
    if(k > 36) {
        puts("-1");
        return 0;
    }
    cnt6 = k & 1;
    cnt8 = k / 2;
    for(int i = 0; i < cnt8; ++i) {
        putchar('8');
    }
    for(int i = 0; i < cnt6; ++i) {
        putchar('6');
    }
    return 0;
}
