#include <stdio.h>

int main()
{
    int n;
    char str[4] = "aabb";
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        putchar(str[i & 3]);
    }
    putchar('\n');
    return 0;
}
