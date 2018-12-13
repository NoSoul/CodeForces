#include <stdio.h>

int Cnt[101];

int main()
{
    int n, m, a;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &a);
        ++Cnt[a];
    }
    for(int i = 100; i >= 1; --i) {
        int cur = 0;
        for(int j = 1; j < 101; ++j) {
            cur += Cnt[j] / i;
        }
        if(cur >= n) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", 0);
    return 0;
}
