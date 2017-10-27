#include <stdio.h>

char Visited[26];

int main()
{
    char Str[101];
    int N, i;
    scanf("%d %s", &N, Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] >= 'a' && Str[i] <= 'z') {
            Visited[Str[i] - 'a'] = 1;
        } else {
            Visited[Str[i] - 'A'] = 1;
        }
    }
    for(i = 0; i < 26; ++i) {
        if(!Visited[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
