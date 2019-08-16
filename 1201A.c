#include <stdio.h>

int main()
{
    int n, m, a;
    char str[1001];
    int cnt[1000][5] = {0};
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        for(int j = 0; j < m; ++j) {
            ++cnt[j][str[j] - 'A'];
        }
    }
    int sum = 0;
    for(int i = 0; i < m; ++i) {
        scanf("%d", &a);
        int idx = 0;
        for(int j = 1; j < 5; ++j) {
            if(cnt[i][j] > cnt[i][idx]) {
                idx = j;
            }
        }
        sum += cnt[i][idx] * a;
    }
    printf("%d\n", sum);
    return 0;
}
