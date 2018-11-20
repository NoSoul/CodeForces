#include <stdio.h>

int Hash[26];

int main()
{
    int  i;
    char Str[101];
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        Hash[Str[i] - 'A']++;
    }
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        Hash[Str[i] - 'A']++;
    }
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        Hash[Str[i] - 'A']--;
    }
    for(i = 0; i < 26; ++i) {
        if(Hash[i] != 0) {
            break;
        }
    }
    puts(i == 26 ? "YES" : "NO");
    return 0;
}
