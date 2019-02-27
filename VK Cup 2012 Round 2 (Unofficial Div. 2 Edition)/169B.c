#include <stdio.h>

int Cnt[10];

int main()
{
    char a[100001];
    char s[100001];
    scanf("%s %s", a, s);
    for(int i = 0; s[i]; ++i) {
        ++Cnt[s[i] - '0'];
    }
    for(int i = 0; a[i]; ++i) {
        for(int j = 9; j > a[i] - '0'; --j) {
            if(Cnt[j]) {
                --Cnt[j];
                a[i] = '0' + j;
                break;
            }
        }
        putchar(a[i]);
    }
    return 0;
}
