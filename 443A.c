#include <stdio.h>
#include <string.h>

char Hash[26];

int main()
{
    int i, Len, Ans = 0;
    char Str[1001];
    gets(Str);
    Len = strlen(Str);
    for(i = 0; i < Len; ++i) {
        if(Str[i] >= 'a' && Str[i] <= 'z') {
            if(!Hash[Str[i] - 'a']) {
                ++Ans;
                Hash[Str[i] - 'a'] = 1;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
