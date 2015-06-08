#include <stdio.h>

int main()
{
    int  i, Top;
    char Template[6] = {"hello"};
    char Str[101];
    scanf("%s", Str);
    for(Top = i = 0; Str[i] != '\0' && Top < 5; ++i) {
        if(Str[i] == Template[Top]) {
            ++Top;
        }
    }
    puts(Top == 5 ? "YES" : "NO");
    return 0;
}
