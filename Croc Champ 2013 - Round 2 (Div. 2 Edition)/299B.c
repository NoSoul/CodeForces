#include <stdio.h>

int main()
{
    int n, k, last = 0;
    char str[300001];
    scanf("%d %d %s", &n, &k, str);
    for(int i = 1; i < n; ++i) {
        if(str[i] == '.' && last + k >= i) {
            last = i;
        }
    }
    if(str[n - 1] == '.' && last + k >= n - 1) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
