#include <stdio.h>
#include <string.h>

int main()
{
    int Ans = 20, N, i;
    char Str[21], Pre[21];
    scanf("%d %s", &N, Pre);
    while(--N)
    {
        scanf("%s", Str);
        for(i = 0; Str[i] != '\0' && i < Ans; ++i)
        {
            if(Str[i] != Pre[i])
            {
                break;
            }
        }
        Ans = i;
        strcpy(Pre, Str);
    }
    printf("%d\n", Ans);
    return 0;
}
