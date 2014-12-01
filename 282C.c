#include <stdio.h>
#include <string.h>

char Src[1000001], Dst[1000001];

int main()
{
    int i, j, Cnts, Cntd, Lens, Lend;
    scanf("%s %s", Src, Dst);
    if(strlen(Src) != strlen(Dst))
    {
        puts("NO");
        return 0;
    }
    if(strcmp(Src, Dst) == 0)
    {
        puts("YES");
        return 0;
    }
    if(strlen(Src) == 1)
    {
        puts(Src[0] == Dst[0] ? "YES" : "NO");
        return 0;
    }
    for(i = 0; Src[i] != '\0'; ++i)
    {
        if(Src[i] == '1')
        {
            break;
        }
    }
    for(j = 0; Dst[j] != '\0'; ++j)
    {
        if(Dst[j] == '1')
        {
            break;
        }
    }
    puts(Src[i] == '1' && Dst[j] == '1' ? "YES" : "NO");
    return 0;
}
