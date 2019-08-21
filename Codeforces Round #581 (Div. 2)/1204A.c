#include <stdio.h>
#include <string.h>

int main()
{
    char str[101];
    scanf("%s", str);
    int ans = (strlen(str) + 1) / 2;
    int cnt = 0;
    for(int i = 0; str[i]; ++i) {
        cnt += str[i] == '1';
    }
    if(cnt == 1 && (strlen(str) & 1)) {
        --ans;
    }
    if(strlen(str) == 1 && str[0] == '0') {
        puts("0");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}
