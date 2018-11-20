#include <stdio.h>
#include <string.h>

int Judge(char *S)
{
    int i, Len;
    Len = strlen(S);
    for(i = 1; i < Len; ++i) {
        if(S[i] > 'Z') {
            break;
        }
    }
    if(i == Len) {
        return 1;
    }
    return 0;
}

int main()
{
    int  i, Len;
    char Str[100];
    scanf("%s", Str);
    Len = strlen(Str);
    if(!Judge(Str)) {
        puts(Str);
    } else {
        for(i = 0; i < Len; ++i) {
            if(Str[i] < 'a') {
                printf("%c", Str[i] - 'A' + 'a');
            } else {
                printf("%c", Str[i] - 'a' + 'A');
            }
        }
        printf("\n");
    }
    return 0;
}
