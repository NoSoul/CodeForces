#include <stdio.h>

int main()
{
    int a, b, cur = 0;
    char flagIn = 0;
    char Str[256];
    scanf("%*d %s", Str);
    a = 0;
    b = 0;
    for(int i = 0; Str[i] != '\0'; ++i) {
        if((Str[i] >= 'a' && Str[i] <= 'z') || (Str[i] >= 'A' && Str[i] <= 'Z')) {
            ++cur;
        } else {
            if(flagIn) {
                if(cur) {
                    ++b;
                }
            } else {
                if(cur > a) {
                    a = cur;
                }
            }
            cur = 0;
        }
        if(Str[i] == '(') {
            flagIn = 1;
        }
        if(Str[i] == ')') {
            flagIn = 0;
        }
    }
    if(cur > a) {
        a = cur;
    }
    printf("%d %d\n", a, b);
    return 0;
}
