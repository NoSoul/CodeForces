#include <stdio.h>

int main()
{
    int i;
    char Str[100001];
    char AB = 0, BA = 0;
    scanf("%s", Str);
    for(i = 0; Str[i + 1] != '\0'; ++i) {
        if(Str[i] == 'A' && Str[i + 1] == 'B') {
            AB = 1;
            i += 2;
            break;
        }
    }
    for(; Str[i + 1] != '\0'; ++i) {
        if(Str[i] == 'B' && Str[i + 1] == 'A') {
            BA = 1;
            break;
        }
    }
    if(AB && BA) {
        puts("YES");
        return 0;
    }
    AB = 0;
    BA = 0;
    for(i = 0; Str[i + 1] != '\0'; ++i) {
        if(Str[i] == 'B' && Str[i + 1] == 'A') {
            BA = 1;
            i += 2;
            break;
        }
    }
    for(; Str[i + 1] != '\0'; ++i) {
        if(Str[i] == 'A' && Str[i + 1] == 'B') {
            AB = 1;
            break;
        }
    }
    puts(AB & BA ? "YES" : "NO");
    return 0;
}
