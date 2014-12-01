#include <stdio.h>
#include <string.h>

int  Now, i, L;
char Str[51];

void Judge_Protocol()
{
    if(Str[Now] == 'f')
    {
        printf("ftp://");
        Now += 3;
    }
    else
    {
        printf("http://");
        Now += 4;
    }
    return;
}

void Judge_Domain()
{
    printf("%c", Str[Now]);
    for(i = Now + 1; i < L; ++i)
    {
        if(Str[i] == 'r' && Str[i + 1] == 'u')
        {
            break;
        }
        printf("%c", Str[i]);
    }
    printf(".ru");
    Now = i + 2;
    return;
}

void Judge_Context()
{
    if(Now == L)
    {
        return;
    }
    printf("/");
    for(i = Now; i < L; ++i)
    {
        printf("%c", Str[i]);
    }
    printf("\n");
    return;
}

int main()
{
    scanf("%s", Str);
    Now = 0;
    L = strlen(Str);
    Judge_Protocol();
    Judge_Domain();
    Judge_Context();
    return 0;
}
