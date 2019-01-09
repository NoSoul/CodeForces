#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ans;
    scanf("%d", &ans);
    for(int i = 0; i < 3; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(ans == a) {
            ans = b;
        } else if(ans == b) {
            ans = a;
        }
    }
    printf("%d\n", ans);
    return 0;
}
