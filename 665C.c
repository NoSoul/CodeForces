#include <stdio.h>

int main()
{
    char str[200001];
    scanf("%s", str);
    putchar(str[0]);
    for(int i = 1; str[i]; ++i) {
        if(str[i] == str[i - 1]) {
            for(int j = 0; j < 26; ++j) {
                if(j + 'a' != str[i - 1] && j + 'a' != str[i + 1]) {
                    str[i] = j + 'a';
                    break;
                }
            }
        }
        putchar(str[i]);
    }
    return 0;
}
