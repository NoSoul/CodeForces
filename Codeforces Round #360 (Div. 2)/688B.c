#include <stdio.h>
#include <string.h>

int main()
{
    char str[100001];
    scanf("%s", str);
    int len = strlen(str);
    printf("%s", str);
    for(int i = len - 1; i >= 0; --i) {
        putchar(str[i]);
    }
    puts("");
    return 0;
}
