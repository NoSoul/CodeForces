#include <stdio.h>

char Flag[300][300];

int main()
{
    int N, i, j;
    char Dia, Oth;
    char Str[300][300];
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%s", Str[i]);
    }
    Dia = Str[0][0];
    Oth = Str[0][1];
    if(Dia == Oth)
    {
        puts("NO");
        return 0;
    }
    for(i = 0; i < N; ++i)
    {
        Flag[i][i] = 1;
    }
    for(i = N - 1, j = 0; j < N; --i, ++j)
    {
        Flag[i][j] = 1;
    }
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            if(Flag[i][j] && Str[i][j] != Dia)
            {
                puts("NO");
                return 0;
            }
            if(Flag[i][j] == 0 && Str[i][j] != Oth)
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
