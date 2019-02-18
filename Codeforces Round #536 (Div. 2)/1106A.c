#include <stdio.h>

int main()
{
    char map[500][501];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    int cnt = 0;
    for(int i = 1; i < n - 1; ++i) {
        for(int j = 1; j < n - 1; ++j) {
            cnt += map[i][j] == 'X'
                   && map[i][j] == map[i - 1][j - 1] && map[i][j] == map[i - 1][j + 1]
                   && map[i][j] == map[i + 1][j - 1] && map[i][j] == map[i + 1][j + 1];
        }
    }
    printf("%d\n", cnt);
    return 0;
}
