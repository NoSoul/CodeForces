#include <stdio.h>

int main()
{
    int i;
    char Str[20];
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i)
    {
        if(Str[i] == '9' && i == 0)
        {
            continue;
        }
        if(Str[i] > '4')
        {
            Str[i] = '9' - Str[i] + '0';
        }
    }
    puts(Str);
    return 0;
}
