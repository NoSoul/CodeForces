#include <stdio.h>

int main()
{
    int n, cnt = 0;
    char str[101];
    scanf("%d %s", &n, str);
    for(int i = 0; str[i]; ++i) {
        cnt += str[i] == '0';
    }
    if(cnt != n) {
        putchar('1');
    }
    for(int i = 0; i < cnt; ++i) {
        putchar('0');
    }
    putchar('\n');
    return 0;
}
