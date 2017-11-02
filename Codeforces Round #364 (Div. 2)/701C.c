#include <stdio.h>
#include <string.h>

int Cnt[100001][52];
char Flag[52];

int Check(int a, int b)
{
    int temp[52];
    for(int i = 0; i < 52; ++i) {
        temp[i] = Cnt[b][i] - (a == 0 ? 0 : Cnt[a - 1][i]);
        if(Flag[i] && temp[i] <= 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, ans;
    char str[100001];
    scanf("%d %s", &n, str);
    ans = n;
    for(int i = 0; str[i]; ++i) {
        if(str[i] < 'a') {
            Flag[str[i] - 'A'] = 1;
            ++Cnt[i][str[i] - 'A'];
        } else {
            Flag[str[i] - 'a' + 26] = 1;
            ++Cnt[i][str[i] - 'a' + 26];
        }
        if(i) {
            for(int j = 0; j < 52; ++j) {
                Cnt[i][j] += Cnt[i - 1][j];
            }
        }
    }
    for(int i = 0; i < n - 1; ++i) {
        int left = i;
        int right = n - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(Check(i, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if(Check(i, right)) {
            if(ans > right - i + 1) {
                ans = right - i + 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
