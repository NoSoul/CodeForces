#include <stdio.h>

int main()
{
    int n;
    char str[200001];
    char match[][3] = {"RGB", "RBG", "GRB", "GBR", "BRG", "BGR"};
    scanf("%d %s", &n, str);
    int ans = 200001;
    int idx = -1;
    for(int i = 0; i < 6; ++i) {
        int cur = 0;
        for(int j = 0; str[j]; ++j) {
            if(str[j] != match[i][j % 3]) {
                ++cur;
            }
        }
        if(ans > cur) {
            idx = i;
            ans = cur;
        }
    }
    printf("%d\n", ans);
    for(int j = 0; str[j]; ++j) {
        putchar(match[idx][j % 3]);
    }
    putchar('\n');
    return 0;
}
