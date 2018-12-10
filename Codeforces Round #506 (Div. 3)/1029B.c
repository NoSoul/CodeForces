#include <stdio.h>

int main()
{
    int n, max = 0, cur = 1, a, pre;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(i) {
            if(a <= 2 * pre) {
                ++cur;
            } else {
                if(max < cur) {
                    max = cur;
                }
                cur = 1;
            }
        }
        pre = a;
    }
    if(max < cur) {
        max = cur;
    }
    printf("%d\n", max);
    return 0;
}
