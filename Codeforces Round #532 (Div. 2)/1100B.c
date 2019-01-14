#include <stdio.h>
#include <string.h>

int Flag[100001];

int main()
{
    int n, m, a, Cnt = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &a);
        if(Flag[a] == 0) {
            ++Cnt;
        }
        ++Flag[a];
        if(Cnt == n) {
            Cnt = 0;
            for(int j = 1; j <= n; ++j) {
                --Flag[j];
                Cnt += Flag[j] != 0;
            }
            putchar('1');
        } else {
            putchar('0');
        }
    }
    putchar('\n');
    return 0;
}
