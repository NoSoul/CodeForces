#include <stdio.h>

int main()
{
    char Str[10];
    char Ans[100][10];
    int Cnt = 0, i, j;
    scanf("%s", Str);
    while(1)
    {
        i = j = 0;;
        while(Str[i] == '0')
        {
            ++i;
        }
        if(Str[i] == '\0')
        {
            break;
        }
        for(; Str[i] != '\0'; ++i)
        {
            if(Str[i] > '0')
            {
                --Str[i];
                Ans[Cnt][j++] = '1';
            }
            else
            {
                Ans[Cnt][j++] = '0';
            }
        }
        Ans[Cnt++][j++] = '\0';
    }
    printf("%d\n", Cnt);
    for(i = 0; i < Cnt; ++i)
    {
        printf("%s ", Ans[i]);
    }
    puts("");
    return 0;
}
