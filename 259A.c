#include <stdio.h>
#include <string.h>

int main()
{
    int i, Flag;
    char Str[10];
    for(i = 0, Flag = 1; i < 8; ++i)
    {
        scanf("%s", Str);
        if(!(strcmp(Str, "WBWBWBWB") == 0 || strcmp(Str, "BWBWBWBW") == 0))
        {
            Flag = 0;
        }
    }
    puts(Flag ? "YES" : "NO");
    return 0;
}
