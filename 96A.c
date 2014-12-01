#include <stdio.h>

int main()
{
    int  i, cnt;
    char Str[101];
    scanf("%s", Str);
    for(cnt = i = 1; Str[i] != '\0'; ++i)
    {
        if(Str[i] == Str[i - 1])
        {
            ++cnt;
            if(cnt == 7)
            {
                break;
            }
            continue;
        }
        cnt = 1;
    }
    puts(cnt == 7 ? "YES" : "NO");
    return 0;
}
