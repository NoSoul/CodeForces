#include <stdio.h>

int main()
{
    int i, Cnti, Cnta, flagi;
    char Str[200001];
    scanf("%*d %s", Str);
    for(Cnti = Cnta = flagi = i = 0; Str[i] != '\0'; ++i)
    {
        if(Str[i] == 'I')
        {
            flagi = 1;
            ++Cnti;
        }
        else if(Str[i] == 'A')
        {
            ++Cnta;
        }
    }
    if(flagi)
    {
        if(Cnti == 1)
        {
            printf("%d\n", Cnti);
        }
        else
        {
            printf("0\n");
        }
    }
    else
    {
        printf("%d\n", Cnta);
    }
    return 0;
}
