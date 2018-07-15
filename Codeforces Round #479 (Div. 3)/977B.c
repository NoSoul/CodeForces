#include <stdio.h>

int main()
{
    int n;
    int max = 0;
    char ans[2];
    char str[101];
    scanf("%d %s", &n, str);
    for(int i = 0; i < n - 1; ++i) {
        int cnt = 1;
        for(int j = i + 1; j < n - 1; ++j) {
            if(str[j] == str[i] && str[j + 1] == str[i + 1]) {
                ++cnt;
            }
        }
        if(max < cnt) {
            max = cnt;
            ans[0] = str[i];
            ans[1] = str[i + 1];
        }
    }
    printf("%c%c\n", ans[0], ans[1]);
    return 0;
}
