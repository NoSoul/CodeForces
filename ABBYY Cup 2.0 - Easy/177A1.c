#include <stdio.h>

char flag[101][101];

int main()
{
    int n, a;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        flag[i][i] = 1;
        flag[i][n - 1 - i] = 1;
        flag[n / 2][i] = 1;
        flag[i][n / 2] = 1;
    }
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &a);
            sum += flag[i][j] * a;
        }
    }
    printf("%d\n", sum);
    return 0;
}
