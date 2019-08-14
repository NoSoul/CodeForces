#include <stdio.h>
#include <string.h>

int main()
{
    char str[11];
    scanf("%s", str);
    int len = strlen(str);
    unsigned ans = 1;
    for(int i = 0; i < len; ++i) {
        ans *= str[i] - '0';
    }
    for(int i = 0; i < len; ++i) {
        if(str[i] != '0') {
            unsigned cur = 1;
            for(int j = 0; j < i; ++j) {
                cur *= str[j] - '0';
            }
            cur *= str[i] - '0' - 1;
            if(str[i] == '1' && i == 0) {
                cur = 1;
            }
            for(int j = i + 1; j < len; ++j) {
                cur *= 9;
            }
            if(ans < cur) {
                ans = cur;
            }
        }
    }
    printf("%u\n", ans);
    return 0;
}
