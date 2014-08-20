#include <stdio.h>

int main()
{
    int N, i, Sum;
    char Str[201];
    scanf("%d", &N);
    scanf("%s", Str);
    for(Sum=i=0; Str[i]!='\0'; ++i)
    {
        if(Str[i] == 'X')
        {
            ++Sum;
        }
    }
    if(Sum == N/2)
    {
        puts("0");
    }
    else if(Sum < N/2)
    {
        printf("%d\n", N/2-Sum);
        for(i=0; Str[i]!='\0'; ++i)
        {
            if(Str[i] == 'x')
            {
                Str[i] = 'X';
                if(++Sum == N/2)
                {
                    break;
                }
            }
        }
    }
    else
    {
        printf("%d\n", Sum-N/2);
        for(i=0; Str[i]!='\0'; ++i)
        {
            if(Str[i] == 'X')
            {
                Str[i] = 'x';
                if(--Sum == N/2)
                {
                    break;
                }
            }
        }
    }
    puts(Str);
    return 0;
}
