#include <stdio.h>

int main()
{
    int n, pre, cur;
    pre = cur = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        if(i == cur) {
            int temp = cur;
            cur += pre;
            pre = temp;
            putchar('O');
        } else {
            putchar('o');
        }
    }
    putchar('\n');
    return 0;
}
