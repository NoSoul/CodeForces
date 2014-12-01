#include <stdio.h>
#include <string.h>

int main()
{
    int  i, N, Len;
    char a, b;
    char Str[101];
    scanf("%d%*c", &N);
    for(i = 0; i < N; ++i)
    {
        gets(Str);
        Len = strlen(Str);
        a = b = 0;
        if(Len > 4)
        {
            if(Str[Len - 5] == 'l' && Str[Len - 4] == 'a' && Str[Len - 3] == 'l' && Str[Len - 2] == 'a' && Str[Len - 1] == '.')
            {
                a = 1;
            }
            if(Str[0] == 'm' && Str[1] == 'i' && Str[2] == 'a' && Str[3] == 'o' && Str[4] == '.')
            {
                b = 1;
            }
            if(a != b)
            {
                puts(a ? "Freda's" : "Rainbow's");
                continue;
            }
        }
        puts("OMG>.< I don't know!");
    }
    return 0;
}
