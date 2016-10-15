#include <stdio.h>
#include <string.h>

char Str[100001];

int main()
{
    int b, e;
    scanf("%s", Str);
    b = -1;
    e = -1;
    for(int i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] != 'a') {
            if(b == -1) {
                b = i;
            }
        } else {
            if(b != -1 && e == - 1) {
                e = i;
            }
        }
    }
    if(b != -1 && e == -1) {
        e = strlen(Str);
    }
    if(b == -1 && e == -1) {
        Str[strlen(Str) - 1] = 'z';
    }
    for(int i = b; i < e; ++i) {
        --Str[i];
    }
    puts(Str);
    return 0;
}
