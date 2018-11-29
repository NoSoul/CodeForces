#include <stdio.h>

int main()
{
    int n, pre = 0x7fffffff, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        if(a > b) {
            if(a <= pre) {
                pre = a;
            } else if(b <= pre) {
                pre = b;
            } else {
                puts("NO");
                return 0;
            }
        } else {
            if(b <= pre) {
                pre = b;
            } else if(a <= pre) {
                pre = a;
            } else {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
