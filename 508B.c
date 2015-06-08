#include <stdio.h>
#include <string.h>

int main()
{
    int i, Len;
    char Str[100001];
    scanf("%s", Str);
    Len = strlen(Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        if((!((Str[i] - '0') & 1)) && Str[i] < Str[Len - 1]) {
            char temp = Str[i];
            Str[i] = Str[Len - 1];
            Str[Len - 1] = temp;
            puts(Str);
            return 0;
        }
    }
    for(i = Len - 2; i >= 0; --i) {
        if(!((Str[i] - '0') & 1)) {
            char temp = Str[i];
            Str[i] = Str[Len - 1];
            Str[Len - 1] = temp;
            puts(Str);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
