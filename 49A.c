#include <stdio.h>
#include <string.h>

int main()
{
    int  i, Len;
    char Str[101];
    gets(Str);
    Len = strlen(Str);
    for(i = Len - 1; i >= 0; --i)
    {
        if((Str[i] >= 'a' && Str[i] <= 'z') || (Str[i] >= 'A' && Str[i] <= 'Z'))
        {
            break;
        }
    }
    if( Str[i] == 'a' || Str[i] == 'e' || Str[i] == 'i' || Str[i] == 'o' || Str[i] == 'u' || Str[i] == 'y' || \
            Str[i] == 'A' || Str[i] == 'E' || Str[i] == 'I' || Str[i] == 'O' || Str[i] == 'U' || Str[i] == 'Y')
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}
