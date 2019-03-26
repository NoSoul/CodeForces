#include <stdio.h>

int Check(char *s)
{
    int a, b, c;
    a = b = c = 0;
    for(int i = 0; i < 3; ++i) {
        if(s[i] == 'A') {
            ++a;
        } else if(s[i] == 'B') {
            ++b;
        } else if(s[i] == 'C') {
            ++c;
        }
    }
    return (a == 1 && b == 1 && c == 1);
}

int main()
{
    char s[101];
    scanf("%s", s);
    for(int i = 0; s[i + 2] != '\0'; ++i) {
        if(Check(s + i)) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
