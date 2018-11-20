#include <stdio.h>

int main()
{
    int n, ans = 0;
    int table[] = {1, 5, 10, 20, 100};
    scanf("%d", &n);
    for(int i = 4; i >= 0; --i) {
        ans += n / table[i];
        n %= table[i];
    }
    printf("%d\n", ans);
    return 0;
}
