#include <stdio.h>

int main()
{
    int n, pre, a;
    int ans[1000];
    int cnt = 0;
    scanf("%d %d", &n, &pre);
    for(int i = 1; i < n; ++i) {
        scanf("%d", &a);
        if(a <= pre) {
            ans[cnt++] = pre;
        }
        pre = a;
    }
    ans[cnt++] = pre;
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
