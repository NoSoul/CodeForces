#include <stdio.h>

int Hash[26];

int main()
{
    int i, Cnt;
    char  Str[1001];
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        ++Hash[Str[i] - 'a'];
    }
    for(Cnt = i = 0; i < 26; ++i) {
        if(Hash[i] & 1) {
            ++Cnt;
        }
    }
    puts((Cnt == 0 || Cnt & 1) ? "First" : "Second");
    return 0;
}
