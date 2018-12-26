#include <stdio.h>

int main()
{
    char str[201];
    scanf("%s", str);
    for(int i = 0; str[i]; ++i) {
        if(str[i] == '.') {
            putchar('0');
        } else {
            putchar(str[i + 1] == '.' ? '1' : '2');
            ++i;
        }
    }
    putchar('\n');
    return 0;
}
