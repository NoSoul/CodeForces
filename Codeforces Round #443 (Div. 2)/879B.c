#include <stdio.h>

#define MAX(a, b)   ((a)>(b)?(a):(b))

int main()
{
    int n, cur, cnt;
    long long k;
    int a[500];
    scanf("%d %I64d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    cur = MAX(a[0], a[1]);
    cnt = 1;
    for(int i = 2; i < n; ++i) {
        if(cur == MAX(cur, a[i])) {
            if(++cnt == k) {
                printf("%d\n", cur);
                return 0;
            }
        } else {
            cur = MAX(cur, a[i]);
            cnt = 1;
        }
    }
    printf("%d\n", cur);
    return 0;
}
