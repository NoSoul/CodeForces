#include <stdio.h>

char Flag[200001];

int main()
{
    int n, a;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        Flag[a + 100000] = 1;
    }
    int ans = 0;
    Flag[100000] = 0;
    for(int i = 0; i < 200001; ++i) {
        ans += Flag[i];
    }
    printf("%d\n", ans);
    return 0;
}
