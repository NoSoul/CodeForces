#include <stdio.h>
#include <string.h>

int main()
{
    int  N, Top, i, Len;
    char Stack[1100], Str[210];
    while(scanf("%d%*c", &N) != EOF) {
        Top = 0;
        Stack[Top++] = '/';
        while(N--) {
            gets(Str);
            if(Str[0] == 'c') {
                sscanf(Str, "%*s %s", Str);
                Len = strlen(Str);
                if(Str[0] == '/') {
                    Top = 0;
                    Stack[Top++] = '/';
                } else {
                    if(Stack[Top - 1] != '/') {
                        Stack[Top++] = '/';
                    }
                }
                for(i = 0; i < Len; ++i) {
                    if(Str[i] == '.') {
                        if(Stack[Top - 1] == '/') {
                            --Top;
                        }
                        while(Stack[Top - 1] != '/') {
                            --Top;
                        }
                        ++i;
                    } else {
                        if(Str[i] == '/' && Stack[Top - 1] == '/') {
                            continue;
                        }
                        Stack[Top++] = Str[i];
                    }
                }
            } else {
                if(Stack[Top - 1] != '/') {
                    Stack[Top++] = '/';
                }
                Stack[Top] = '\0';
                puts(Stack);
            }
        }
    }
    return 0;
}
