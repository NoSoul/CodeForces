#include <stdio.h>

int main()
{
    char str[100001];
    scanf("%s", str);
    int j = -1;
    int cntA = 0;
    int cntB = 0;
    for(int i = 0; str[i]; ++i) {
        if(str[i] == '0') {
            if(j == -1) {
                ++cntA;
            }
        } else if(str[i] == '1') {
            ++cntB;
        } else {
            if(j == -1) {
                j = i;
            }
        }
    }
    for(int i = 0; i < cntA; ++i) {
        putchar('0');
    }
    for(int i = 0; i < cntB; ++i) {
        putchar('1');
    }
    for(int i = j; str[i]; ++i) {
        if(str[i] != '1') {
            putchar(str[i]);
        }
    }
    putchar('\n');
    return 0;
}
