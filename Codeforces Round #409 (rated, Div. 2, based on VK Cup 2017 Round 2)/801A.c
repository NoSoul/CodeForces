#include <stdio.h>

char Flag[101];

int main()
{
    char str[101];
    int cnt = 0;
    scanf("%s", str);
    for(int i = 0; str[i + 1]; ++i) {
        if(str[i] == 'V' && str[i + 1] == 'K') {
            Flag[i] = 1;
            Flag[i + 1] = 1;
            ++cnt;
        }
    }
    for(int i = 0; str[i + 1]; ++i) {
        if(str[i] == str[i + 1] && !Flag[i] && !Flag[i + 1]) {
            ++cnt;
            break;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
