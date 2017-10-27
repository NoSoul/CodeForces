#include <stdio.h>
#include <string.h>

char Str[100001];

int main()
{
    int i, Pre, Len;
    gets(Str);
    Pre = 0;
    while(1) {
        for(i = Pre; Str[i] != '\0' && Str[i] == ' '; ++i);
        if(Str[i] == '\0') {
            return 0;
        }
        printf("<");
        if(Str[i] == '"') {
            while(++i, Str[i] != '\0' && Str[i] != '"') {
                printf("%c", Str[i]);
            }
        } else {
            printf("%c", Str[i]);
            if(Str[i + 1] == '\0') {
                printf(">\n");
                return 0;
            }
            while(++i, Str[i] != '\0' && Str[i] != ' ') {
                printf("%c", Str[i]);
            }
        }
        printf(">\n");
        if(Str[i] == '\0') {
            return 0;
        }
        Pre = i + 1;
    }
    return 0;
}
