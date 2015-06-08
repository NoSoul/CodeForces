#include <stdio.h>

int main()
{
    int N, i, j;
    char Str[101];
    scanf("%d %s", &N, Str);
    for(i = 0; i + 4 < N; ++i) {
        for(j = 1; i + 4 * j < N; ++j) {
            if(Str[i] == '*' && Str[i + j] == '*' && Str[i + 2 * j] == '*' && Str[i + 3 * j] == '*' && Str[i + 4 * j] == '*') {
                puts("yes");
                return 0;
            }
        }
    }
    puts("no");
    return 0;
}
