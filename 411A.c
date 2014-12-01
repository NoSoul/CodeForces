#include <stdio.h>
#include <string.h>

int main()
{
    int i, A, B, C;
    char Str[101];
    scanf("%s", Str);
    if(strlen(Str) < 5)
    {
        puts("Too weak");
        return 0;
    }
    A = B = C = 0;
    for(i = 0; Str[i] != '\0'; ++i)
    {
        if(Str[i] >= 'A' && Str[i] <= 'Z')
        {
            A = 1;
        }
        else if(Str[i] >= 'a' && Str[i] <= 'z')
        {
            B = 1;
        }
        else if(Str[i] >= '0' && Str[i] <= '9')
        {
            C = 1;
        }
    }
    puts((A & B & C) ? "Correct" : "Too weak");
    return 0;
}
