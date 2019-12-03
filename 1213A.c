#include <stdio.h>

int main()
{
    int n;
    int x[100];
    int cnt[2] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        ++cnt[x[i] & 1];
    }
    printf("%d\n", cnt[0] < cnt[1] ? cnt[0] : cnt[1]);
    return 0;
}
