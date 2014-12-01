#include <stdio.h>

int Hash[10];
char Str[1000001];

int main()
{
    int i, j, Sum;
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i)
    {
        ++Hash[Str[i] - '0'];
    }
    --Hash[1];
    --Hash[6];
    --Hash[8];
    --Hash[9];
    Sum = 0;
    for(i = 1; i < 10; ++i)
    {
        for(j = 0; j < Hash[i]; ++j)
        {
            Sum = Sum * 10 + i;
            Sum %= 7;
            printf("%c", i + '0');
        }
    }
    for(i = 0; i < 4; ++i)
    {
        Sum *= 10;
        Sum %= 7;
    }
    if(Sum == 0)
    {
        printf("1869");
    }
    if(Sum == 1)
    {
        printf("1896");
    }
    if(Sum == 2)
    {
        printf("1986");
    }
    if(Sum == 3)
    {
        printf("1698");
    }
    if(Sum == 4)
    {
        printf("6198");
    }
    if(Sum == 5)
    {
        printf("1689");
    }
    if(Sum == 6)
    {
        printf("1968");
    }
    for(i = 0; i < Hash[0]; ++i)
    {
        printf("0");
    }
    return 0;
}
