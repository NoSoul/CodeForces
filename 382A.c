#include <stdio.h>
#include <string.h>

int main()
{
    int i, res, j;
    char Str[30], extra[30];
    scanf("%s %s", Str, extra);
    res = (strlen(Str) + strlen(extra) - 1) / 2;
    for(i = 0; Str[i] != '|'; ++i);
    if((strlen(Str) + strlen(extra) - 1) % 2 == 1 || i > res || (strlen(Str) - i - 1) > res)
    {
        printf("Impossible\n");
        return 0;
    }
    for(j = 0; j < res - i; ++j)
    {
        printf("%c", extra[j]);
    }
    printf("%s", Str);
    for(j = res - i; j < strlen(extra); ++j)
    {
        printf("%c", extra[j]);
    }
    printf("\n");
    return 0;
}
