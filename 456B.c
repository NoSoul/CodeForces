#include <stdio.h>
#include <string.h>

char Str[100010];

int main()
{
    int Len, Num, i;
    scanf("%s", Str);
    Len = strlen(Str);
    if(Len > 2)
    {
        Str[0] = Str[Len - 2];
        Str[1] = Str[Len - 1];
        Str[2] = '\0';
    }
    for(Num = i = 0; Str[i] != '\0'; ++i)
    {
        Num *= 10;
        Num += Str[i] - '0';
    }
    puts(Num % 4 ? "0" : "4");
    return 0;
}
