#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, Len;
    char Str[8][9] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    char Key[9];
    scanf("%d", &Len);
    scanf("%s", Key);
    for(i=0; i<8; ++i)
    {
        if(Len == strlen(Str[i]))
        {
            for(j=0; j<Len; ++j)
            {
                if(Key[j]=='.' || Key[j]==Str[i][j])
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            if(j == Len)
            {
                puts(Str[i]);
            }
        }
    }
    return 0;
}
