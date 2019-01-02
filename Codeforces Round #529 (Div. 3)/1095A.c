#include <stdio.h>

int main()
{
    int n;
    char str[56];
    scanf("%d %s", &n, str);
    for(int i = 0, j = 1; i < n; i += j, ++j) {
        putchar(str[i]);
    }
    return 0;
}
