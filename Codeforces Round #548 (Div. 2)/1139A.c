#include <stdio.h>

int main()
{
    int n;
    char str[65001];
    scanf("%d %s", &n, str);
    int ans = 0;
    for(int i = 0; str[i]; ++i) {
        int num = str[i] - '0';
        if(!(num & 1)) {
            ans += i + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
