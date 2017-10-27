#include <stdio.h>
#include <string.h>

int Flag[26];

int main()
{
    int K, i, j;
    char Str[101];
    scanf("%d %s", &K, Str);
    for(i = j = 0; Str[i] != '\0'; ++i) {
        if(!Flag[Str[i] - 'a']) {
            Flag[Str[i] - 'a'] = 1;
            ++j;
        }
    }
    if(j < K) {
        puts("NO");
        return 0;
    }
    puts("YES");
    memset(Flag, 0, sizeof(Flag));
    i = 0;
    while(--K) {
        Flag[Str[i] - 'a'] = 1;
        for(; Str[i] != '\0' && Flag[Str[i] - 'a']; ++i) {
            printf("%c", Str[i]);
        }
        puts("");
    }
    puts(Str + i);
    return 0;
}
