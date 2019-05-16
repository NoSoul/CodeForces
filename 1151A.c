#include <stdio.h>

int Fun(int a, int b)
{
    int ret = a - b;
    if(ret < 0) {
        ret += 26;
    }
    if(ret > 13) {
        ret = 26 - ret;
    }
    return ret;
}

int main()
{
    int n;
    char str[51];
    scanf("%d %s", &n, &str);
    int min = 0x7fffffff;
    for(int i = 0; i + 4 <= n; ++i) {
        int cur = Fun(str[i] - 'A', 'A' - 'A') + Fun(str[i + 1] - 'A', 'C' - 'A') + Fun(str[i + 2] - 'A', 'T' - 'A') + Fun(str[i + 3] - 'A', 'G' - 'A');
        if(min > cur) {
            min = cur;
        }
    }
    printf("%d\n", min);
    return 0;
}
