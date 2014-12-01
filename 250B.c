#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, Flag, Cnt, j, k;
    char Str[41], Ans[6], Temp[41];
    scanf("%d", &N);
    while(N--)
    {
        scanf("%s", Str);
        for(Flag = -1, i = 0; Str[i + 1] != '\0'; ++i)
        {
            if(Str[i] == ':' && Str[i + 1] == ':')
            {
                Flag = i;
                break;
            }
        }
        Cnt = 0;
        if(Flag != -1)
        {
            for(i = 0; Str[i + 1] != '\0'; ++i)
            {
                if(Str[i] != ':' && Str[i + 1] == ':')
                {
                    ++Cnt;
                }
            }
            if(Str[i] != ':')
            {
                ++Cnt;
            }
            Cnt = 8 - Cnt;
        }
        for(i = 0; i < Flag; ++i)
        {
            Temp[i] = Str[i];
        }
        while(Cnt--)
        {
            if(i != 0)
            {
                Temp[i++] = ':';
            }
            Temp[i++] = '0';
        }
        for(k = Flag + 1; Str[k] != '\0'; ++k)
        {
            Temp[i++] = Str[k];
        }
        if(Temp[i - 1] == ':')
        {
            --i;
        }
        Temp[i++] = '\0';
        strcpy(Str, Temp);
        for(i = j = 0; Str[i] != '\0'; ++i)
        {
            if(Str[i] != ':')
            {
                Ans[j++] = Str[i];
            }
            else
            {
                for(k = 0; k < 4 - j; ++k)
                {
                    printf("0");
                }
                for(k = 0; k < j; ++k)
                {
                    printf("%c", Ans[k]);
                }
                if(Str[i + 1] != '\0')
                {
                    printf(":");
                }
                j = 0;
            }
        }
        for(k = 0; k < 4 - j; ++k)
        {
            printf("0");
        }
        for(k = 0; k < j; ++k)
        {
            printf("%c", Ans[k]);
        }
        printf("\n");
    }
    return 0;
}
