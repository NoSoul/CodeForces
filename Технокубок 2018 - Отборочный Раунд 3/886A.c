#include <stdio.h>

char dp[7][6001];

int main()
{
    int sum = 0;
    int a[6];
    for(int i = 0; i < 6; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= 6; ++i) {
        for(int j = i; j >= 1; --j) {
            for(int s = 0; s <= sum / 2; ++s) {
                if(s >= a[i - 1] && dp[j - 1][s - a[i - 1]]) {
                    dp[j][s] = 1;
                }
            }
        }
    }
    if(!(sum & 1) && dp[3][sum / 2]) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
