#include <stdio.h>

int main()
{
    int i;
    char Str[100001];
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == '0') {
            Str[i] = '#';
            break;
        }
    }
    if(Str[i] == '\0') {
        Str[i - 1] = '#';
    }
    for(i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] != '#') {
            printf("%c", Str[i]);
        }
    }
    return 0;
}
