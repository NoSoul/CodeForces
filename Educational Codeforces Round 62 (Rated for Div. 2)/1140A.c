#include <stdio.h>

int Cnt[10001];

int main()
{
    int n, a;
    int num = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if(a != i) {
            ++Cnt[a];
            ++num;
        }
        num -= Cnt[i];
        if(num == 0) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
