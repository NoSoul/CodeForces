#include <stdio.h>

int main()
{
    char str[51];
    scanf("%s", str);
    char match[] = {"aeiou"};
    int cnt = 0;
    for(int i = 0; str[i]; ++i) {
        if(str[i] >= '1' && str[i] <= '9' && (str[i] - '0') & 1) {
            ++cnt;
        } else {
            for(int j = 0; j < 5; ++j) {
                if(str[i] == match[j]) {
                    ++cnt;
                }
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
