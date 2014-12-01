#include <stdio.h>

int main()
{
    int i, in, out, Cnt;
    char Str[301];
    scanf("%s", Str);
    in = out = Cnt = 0;
    for(i = 0; Str[i] != '\0'; ++i)
    {
        if(Str[i] == '+')
        {
            in++;
            if(out == 0)
            {
                out = 1;
                Cnt++;
            }
            out--;
        }
        else
        {
            if(in == 0)
            {
                in = 1;
                Cnt++;
            }
            in--;
            out++;
        }
    }
    printf("%d\n", Cnt);
    return 0;
}
