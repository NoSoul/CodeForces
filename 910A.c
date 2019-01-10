#include <stdio.h>

int main()
{
    int n, d;
    char str[101];
    scanf("%d %d %s", &n, &d, str);
    int last = 0, ans = 0;
    while(1) {
        if(last == n - 1) {
            break;
        }
        int find = -1;
        for(int i = d; i > 0; --i) {
            if(last + i < n && str[last + i] == '1') {
                find = i;
                break;
            }
        }
        if(~find) {
            last += find;
            ++ans;
        } else {
            ans = -1;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
