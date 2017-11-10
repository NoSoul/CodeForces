#include <stdio.h>
#include <string.h>

int main()
{
    char str[10];
    scanf("%s", str);
    int len = strlen(str);
    for(int i = len - 1; i >= 0; --i) {
        if(str[i] != '0') {
            str[i + 1] = '\0';
            break;
        }
    }
    len = strlen(str);
    for(int i = 0; i < len / 2; ++i) {
        if(str[i] != str[len - 1 - i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
