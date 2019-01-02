#include <stdio.h>

int main()
{
    int n, s;
    int a[1001];
    int b[1001];
    scanf("%d %d", &n, &s);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    if(a[1] && a[s]) {
        puts("YES");
    } else {
        for(int i = 1; i <= n; ++i) {
            if(a[1] && a[i] && b[i] && b[s] && i >= s) {
                puts("YES");
                return 0;
            }
        }
        puts("NO");
    }
    return 0;
}
