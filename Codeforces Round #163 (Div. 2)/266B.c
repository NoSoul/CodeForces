#include <stdio.h>

int main()
{
    int N, T, i, Cnt;
    char Str[51];
    scanf("%d %d %s", &N, &T, Str);
    while(T--) {
        for(i = 0; Str[i + 1] != '\0'; ++i) {
            if(Str[i] == 'B' && Str[i + 1] == 'G') {
                Str[i] = 'G';
                Str[i + 1] = 'B';
                ++i;
            }
        }
    }
    puts(Str);
    return 0;
}
