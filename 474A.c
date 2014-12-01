#include <stdio.h>

int main()
{
    int i, j;
    char Str[31] = {"qwertyuiopasdfghjkl;zxcvbnm,./"};
    char Cmd[2], Recv[101];
    scanf("%s", Cmd);
    scanf("%s", Recv);
    int offset = 1;
    if(Cmd[0] == 'R')
    {
        offset = -1;
    }
    for(i = 0; Recv[i] != '\0'; ++i)
    {
        for(j = 0; j < 31; ++j)
        {
            if(Recv[i] == Str[j])
            {
                putchar(Str[j + offset]);
                break;
            }
        }
    }
    puts("");
    return 0;
}
