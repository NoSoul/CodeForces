#include <stdio.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int last = 0;
        while(n--) {
            int l, r;
            scanf("%d %d", &l, &r);
            int cur = Max(last, l);
            if(cur <= r) {
                printf("%d ", cur);
                last = cur + 1;
            } else {
                printf("%d ", 0);
            }
        }
        puts("");
    }
    return 0;
}
