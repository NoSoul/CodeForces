#include <stdio.h>

int main()
{
    int N, i, FirstR, FirstL, LastR, LastL;
    char Str[1001];
    scanf("%d %s", &N, Str);
    FirstL = FirstR = LastL = LastR = -1;
    for(i = 0; Str[i] != '\0'; ++i)
    {
        if(Str[i] == 'R')
        {
            if(FirstR == -1)
            {
                FirstR = i;
            }
            LastR = i;
        }
        if(Str[i] == 'L')
        {
            if(FirstL == -1)
            {
                FirstL = i;
            }
            LastL = i;
        }
    }
    if(FirstL == -1 && FirstR != -1)
    {
        printf("%d %d\n", FirstR + 1, LastR + 2);
    }
    if(FirstR == -1 && FirstL != -1)
    {
        printf("%d %d\n", LastL + 1, FirstL);
    }
    if(FirstL != -1 && FirstR != -1)
    {
        printf("%d %d\n", LastL + 1, LastR + 2);
    }
    return 0;
}
