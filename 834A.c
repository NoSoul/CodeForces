#include <stdio.h>

int main()
{
    char Str[4] = {"^>v<"};
    char s, e;
    int n;
    scanf("%c %c %d", &s, &e, &n);
    n %= 4;
    char cw = 0, ccw = 0;
    for(int i = 0; i < 4; ++i) {
        if(Str[i] == s) {
            if(Str[(i + n) & 3] == e) {
                cw = 1;
            }
            if(Str[(i - n + 4) & 3] == e) {
                ccw = 1;
            }
        }
    }
    if(cw + ccw == 2 || cw + ccw == 0) {
        puts("undefined");
    } else {
        puts(cw ? "cw" : "ccw");
    }
    return 0;
}
