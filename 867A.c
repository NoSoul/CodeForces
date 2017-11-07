#include <stdio.h>

int main()
{
    int n, g, b;
    char str[101];
    scanf("%d %s", &n, str);
    g = b = 0;
    for(int i = 1; i < n; ++i) {
        if(str[i] != str[i - 1]) {
            if(str[i] == 'F') {
                ++g;
            } else {
                ++b;
            }
        }
    }
    puts(g > b ? "YES" : "NO");
    return 0;
}
