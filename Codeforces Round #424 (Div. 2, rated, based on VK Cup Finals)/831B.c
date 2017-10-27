#include <stdio.h>

int main()
{
    char StrA[27];
    char StrB[27];
    char StrC[10001];
    scanf("%s %s %s", StrA, StrB, StrC);
    for(int i = 0; StrC[i] != '\0'; ++i) {
        char ch = StrC[i];
        char upper = 0;
        if(ch >= 'A' && ch <= 'Z') {
            upper = 1;
            ch += 'a' - 'A';
        }
        for(int j = 0; j < 26; ++j) {
            if(ch == StrA[j]) {
                ch = StrB[j];
                if(upper) {
                    ch += 'A' - 'a';
                }
                break;
            }
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
