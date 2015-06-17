#include <stdio.h>
#include <string.h>

int main()
{
    char Str[101];
    int p = 0, Len;
    scanf("%s", Str);
    Len = strlen(Str);
    if(Str[0] == '-') {
        p = 1;
        if(Str[Len - 1] > '0') {
            --Str[Len - 1];
        }
        --Len;
    }
    if(Len < 3 || (Len == 3 && strcmp(Str + p, "127") <= 0)) {
        puts("byte");
    } else if(Len < 5 || (Len == 5 && strcmp(Str + p, "32767") <= 0)) {
        puts("short");
    } else if(Len < 10 || (Len == 10 && strcmp(Str + p, "2147483647") <= 0)) {
        puts("int");
    } else if(Len < 19 || (Len == 19 && strcmp(Str + p, "9223372036854775807") <= 0)) {
        puts("long");
    } else {
        puts("BigInteger");
    }
    return 0;
}
