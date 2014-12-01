#include <stdio.h>

char flag[26];

int main()
{
    int i, Cnt;
    char Str[101];
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i)
    {
        flag[Str[i] - 'a'] = 1;
    }
    for(i = Cnt = 0; i < 26; ++i)
    {
        Cnt += flag[i];
    }
    if(Cnt & 1)
    {
        puts("IGNORE HIM!");
    }
    else
    {
        puts("CHAT WITH HER!");
    }
    return 0;
}
