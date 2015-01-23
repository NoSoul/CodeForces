#include <stdio.h>
#include <string.h>

int Check(const char *src)
{
    int i, j, L;
    L = strlen(src);
    for(i = 0, j = L - 1; i < j; ++i, --j)
    {
        if(src[i] != src[j])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i, j, L;
    char Str[11], Dst[12];
    scanf("%s", Str);
    L = strlen(Str);
    for(i = 0; i <= L; ++i)
    {
        for(j = 0; j < 26; ++j)
        {
            Dst[i] = 'a' + j;
            memcpy(Dst, Str, sizeof(char)*i);
            memcpy(Dst + i + 1, Str + i, sizeof(char) * (L - i));
            Dst[L + 1] = '\0';
            if(Check(Dst))
            {
                puts(Dst);
                return 0;
            }
        }
    }
    puts("NA");
    return 0;
}
