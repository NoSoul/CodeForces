#include <stdio.h>

int main()
{
    int n, x, y;
    char str[200001];
    scanf("%d %d %d", &n, &x, &y);
    scanf("%s", str);
    int ans = 0;
    ++y;
    ++x;
    for(int i = n - 1; i > n - y; --i) {
        if(str[i] == '1') {
            ++ans;
        }
    }
    if(str[n - y] == '0') {
        ++ans;
    }
    for(int i = n - y - 1; i > n - x; --i) {
        if(str[i] == '1') {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
