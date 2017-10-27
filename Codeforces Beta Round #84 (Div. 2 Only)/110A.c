#include <stdio.h>

int main()
{
    int  i, j;
    char Str[20];
    scanf("%s", Str);
    for(j = i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == '4' || Str[i] == '7') {
            ++j;
        }
    }
    puts((j == 4 || j == 7) ? "YES" : "NO");
    return 0;
}
