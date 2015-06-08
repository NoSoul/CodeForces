#include <stdio.h>
#include <string.h>

char Str[0][101];

int F(char *s)
{
    int i, cnt, l;
    l = strlen(s);
    for(cnt = i = 0; i < l; ++i) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            ++cnt;
        }
    }
    return cnt;
}

int main()
{
    gets(Str[0]);
    gets(Str[1]);
    gets(Str[2]);
    if(F(Str[0]) == 5 && F(Str[1]) == 7 && F(Str[2]) == 5) {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}
