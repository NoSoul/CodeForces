#include <stdio.h>

int main()
{
    int n, max = 0;
    int a[100001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(max < a[i]) {
            max = a[i];
        }
    }
    int cur = 0, ans = 1;
    for(int i = 0; i < n; ++i) {
        if(a[i] == max) {
            ++cur;
        } else {
            if(ans < cur) {
                ans = cur;
            }
            cur = 0;
        }
    }
    if(ans < cur) {
        ans = cur;
    }
    printf("%d\n", ans);
    return 0;
}
