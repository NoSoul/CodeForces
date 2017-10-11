#include <stdio.h>

int main()
{
    int n, k, count = 0, a, remain = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        remain += a;
        if(remain > 8) {
            count += 8;
            remain -= 8;
        } else {
            count += remain;
            remain = 0;
        }
        if(count >= k) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
