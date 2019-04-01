#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Flag[10001];

int main()
{
    int n, m, k, v;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &k);
        memset(Flag, 0, sizeof(Flag));
        char find = 0;
        for(int j = 0; j < k; ++j) {
            scanf("%d", &v);
            if(Flag[abs(v)] == -v) {
                find = 1;
            }
            Flag[abs(v)] = v;
        }
        if(!find) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
