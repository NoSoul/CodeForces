#include <stdio.h>
#include <string.h>

int main()
{
    char str[51];
    scanf("%s", str);
    int len = strlen(str);
    int offset = 1;
    if(len & 1) {
        printf("%c", str[len / 2]);
        offset = 2;
        for(int i = len / 2 + 1; i < len; ++i, offset += 2) {
            printf("%c%c", str[i], str[i - offset]);
        }
    } else {
        for(int i = len / 2 - 1; i >= 0; --i, offset += 2) {
            printf("%c%c", str[i], str[i + offset]);
        }
    }
    return 0;
}
