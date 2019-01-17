#include <stdio.h>

int main()
{
    int n;
    char str[90];
    scanf("%d %s", &n, str);
    int cnt1 = 0, cnt0 = 0;
    for(int i = 0; str[i]; ++i) {
        if(str[i] == '1') {
            ++cnt1;
        } else {
            printf("%d", cnt1);
            cnt1 = 0;
        }
    }
    printf("%d", cnt1);
    puts("");
    return 0;
}
