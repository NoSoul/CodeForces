#include <stdio.h>
#include <string.h>

int main()
{
    char str[1001];
    scanf("%s", str);
    printf("%s", str);
    for(int i = strlen(str) - 1; i >= 0; --i) {
        putchar(str[i]);
    }
    putchar('\n');
    return 0;
}
