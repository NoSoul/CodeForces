#include <stdio.h>

int main()
{
    int N, Num, g, l, ge, le, i, Type;
    char Str[3], choice[2];
    scanf("%d", &N);
    l = le = 2000000000;
    g = ge = -2000000000;
    while(N--) {
        scanf("%s %d %s", Str, &Num, choice);
        if(Str[0] == '>' && Str[1] == '\0') {
            Type = choice[0] == 'Y' ? 1 : 4;
        } else if(Str[0] == '<' && Str[1] == '\0') {
            Type = choice[0] == 'Y' ? 2 : 3;
        } else if(Str[0] == '>' && Str[1] == '=') {
            Type = choice[0] == 'Y' ? 3 : 2;
        } else if(Str[0] == '<' && Str[1] == '=') {
            Type = choice[0] == 'Y' ? 4 : 1;
        }
        if(Type == 1) {
            if(Num > g) {
                g = Num;
            }
        } else if(Type == 2) {
            if(Num < l) {
                l = Num;
            }
        } else if(Type == 3) {
            if(Num > ge) {
                ge = Num;
            }
        } else if(Type == 4) {
            if(Num < le) {
                le = Num;
            }
        }
    }
    int Min, Max;
    Min = ge > g ? ge : g;
    Max = le < l ? le : l;
    for(i = Min; i <= Max; ++i) {
        if(i > g && i < l && i >= ge && i <= le) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("Impossible");
    return 0;
}
