#include <stdio.h>
#include <string.h>

int main()
{
    int n, pre;
    int p[1001];
    int cnt[1001];
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &pre);
        p[i] = pre;
    }
    for(int i = 1; i <= n; ++i) {
        memset(cnt, 0, sizeof(cnt));
        cnt[i] = 1;
        int find = i;
        while(1) {
            find = p[find];
            if(++cnt[find] == 2) {
                printf("%d ", find);
                break;
            }
        }
    }
    return 0;
}
