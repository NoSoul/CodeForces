#include <stdio.h>

char Flag[26];

int main()
{
    char str[501];
    scanf("%s", str);
    int except = 0;
    char flag = 1;
    for(int i = 0; str[i]; ++i) {
        if(!Flag[str[i] - 'a']) {
            if(except == str[i] - 'a') {
                Flag[str[i] - 'a'] = 1;
                ++except;
            } else {
                flag = 0;
            }
        }
    }
    puts(flag ? "YES" : "NO");
    return 0;
}
