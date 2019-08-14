#include <stdio.h>

int main()
{
    int n, cnt[2] = {0};
    char a[200000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    for(int i = 0; i < n; ++i) {
        if(--cnt[a[i]] == 0) {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}
