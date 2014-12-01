#include <stdio.h>

int main()
{
    int  i, flag;
    char Str1[101], Str2[101];
    scanf("%s %s", Str1, Str2);
    for(flag = i = 0; Str1[i] != '\0'; ++i)
    {
        if(Str1[i] < 'a')
        {
            Str1[i] += 32;
        }
        if(Str2[i] < 'a')
        {
            Str2[i] += 32;
        }
        if(Str1[i] < Str2[i])
        {
            flag = -1;
            break;
        }
        if(Str1[i] > Str2[i])
        {
            flag = 1;
            break;
        }
    }
    printf("%d\n", flag);
    return 0;
}
