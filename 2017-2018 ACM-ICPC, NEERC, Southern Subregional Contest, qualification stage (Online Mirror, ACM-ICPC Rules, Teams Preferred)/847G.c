#include <stdio.h>

int Cnt[7];

int main()
{
    int n;
    char str[8];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        for(int j = 0; j < 8; ++j) {
            if(str[j] == '1') {
                ++Cnt[j];
            }
        }
    }
    int ans = Cnt[0];
    for(int i = 1; i < 8; ++i) {
        if(ans < Cnt[i]) {
            ans = Cnt[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
