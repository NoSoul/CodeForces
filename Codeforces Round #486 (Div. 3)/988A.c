#include <stdio.h>
#include <string.h>

int main()
{
    int n, k, a;
    int flag[101];
    memset(flag, 0, sizeof(flag));
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        flag[a] = i + 1;
    }
    int cnt = 0;
    for(int i = 0; i < 101; ++i) {
        cnt += flag[i] != 0;
    }
    if(cnt < k) {
        puts("NO");
    } else {
        puts("YES");
        cnt = 0;
        for(int i = 0; i < 101; ++i) {
            if(flag[i]) {
                printf("%d ", flag[i]);
                if(++cnt == k) {
                    puts("\n");
                    break;
                }
            }
        }
    }
    return 0;
}
