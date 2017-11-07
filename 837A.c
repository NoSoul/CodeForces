#include <stdio.h>

int main()
{
    int n, cur, ans;
    char str[201];
    scanf("%d\n", &n);
    fgets(str, 201, stdin);
    cur = ans = 0;
    for(int i = 0; i < n; ++i) {
        if(str[i] == ' ') {
            if(ans < cur) {
                ans = cur;
            }
            cur = 0;
        } else {
            if(str[i] < 'a') {
                ++cur;
            }
        }
    }
    if(ans < cur) {
        ans = cur;
    }
    printf("%d\n", ans);
    return 0;
}
