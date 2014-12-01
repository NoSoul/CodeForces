#include <stdio.h>

int main()
{
    int  i;
    char Str1[101], Str2[101];
    scanf("%s %s", Str1, Str2);
    for(i = 0; Str1[i] != '\0'; ++i)
    {
        Str1[i] = ((Str1[i] - '0') ^ (Str2[i] - '0')) + '0';
    }
    puts(Str1);
    return 0;
}
