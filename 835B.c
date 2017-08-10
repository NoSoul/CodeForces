#include <stdio.h>

int cnt[10];

int main()
{
    int k, sum = 0, ans = 0;
    char str[100001];
    scanf("%d %s", &k, str);
    for(int i = 0; str[i] != '\0'; ++i) {
        sum += str[i] - '0';
        ++cnt[str[i] - '0'];
    }
    if(sum >= k) {
        puts("0");
    } else {
        sum = k - sum;
        for(int i = 0; i < 9; ++i) {
            if(cnt[i] * (9 - i) >= sum) {
                ans += (sum + 9 - i - 1) / (9 - i);
                break;
            } else {
                ans += cnt[i];
                sum -= cnt[i] * (9 - i);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
