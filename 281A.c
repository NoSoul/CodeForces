#include <stdio.h>

int main()
{
    char  Str[1001];
    scanf("%s", Str);
    if(Str[0] >= 'a' && Str[0] <= 'z')
    {
        Str[0] = Str[0] - 'a' + 'A';
    }
    puts(Str);
    return 0;
}
