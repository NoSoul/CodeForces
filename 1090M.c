#include <stdio.h>

int main()
{
    int n, k, pre, a;
    scanf("%d %d", &n, &k);
    scanf("%d", &pre);
    int cur = 1, max = 1;
    for(int i = 1; i < n; ++i) {
        scanf("%d", &a);
        if(a != pre) {
            ++cur;
        } else {
            if(max < cur) {
                max = cur;
            }
            cur = 1;
        }
        pre = a;
    }
    if(max < cur) {
        max = cur;
    }
    printf("%d\n", max);
    return 0;
}
