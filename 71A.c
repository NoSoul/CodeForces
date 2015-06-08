#include <stdio.h>
#include <string.h>

int main()
{
    int T, Len;
    char Str[101];
    scanf("%d", &T);
    while(T--) {
        scanf("%s", Str);
        Len = strlen(Str);
        if(Len > 10) {
            printf("%c%d%c\n", Str[0], Len - 2, Str[Len - 1]);
            continue;
        }
        puts(Str);
    }
    return 0;
}
