#include <stdio.h>
#include <string.h>

int main()
{
    char Str[21];
    int Ans = 0;
    scanf("%s", Str);
    Ans = strlen(Str);
    Ans = (Ans + 1) * 26 - Ans;
    printf("%d\n", Ans);
    return 0;
}
