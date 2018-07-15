#include <stdio.h>

int main()
{
    int n, ans = 0;
    char str[101];
    scanf("%d %s", &n, str);
    for(int i = 0; i < n - 2; ++i) {
        if(str[i] == 'x' && str[i + 1] == 'x') {
            int j = i + 2;
            for(; j < n; ++j) {
                if(str[j] == 'x') {
                    ++ans;
                } else {
                    break;
                }
            }
            i = j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
